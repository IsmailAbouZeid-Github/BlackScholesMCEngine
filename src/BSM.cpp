#include "BSM.hpp"

BSM::BSM(constructorArgs &args) {
  this->_asset = args.asset;
  this->_strike = args.strike;
  this->_volatility = args.volatility;
  this->_growth = args.growth;
  this->_years = args.years;
  this->_steps = args.steps;
  this->_simulations = args.simulations;
  this->_mt_engine = std::mt19937(std::random_device()());
}
BSM::~BSM() {}
float BSM::get_asset() const { return this->_asset; }
float BSM::get_strike() const { return this->_strike; }
float BSM::get_volatility() const { return this->_volatility; }
float BSM::get_growth() const { return this->_growth; }
float BSM::get_years() const { return this->_years; }

long int BSM::get_steps() const { return this->_steps; }
long int BSM::get_simulations() const { return this->_simulations; }

double BSM::get_call_price() { return this->_call_price; }
double BSM::get_put_price() { return this->_put_price; }

void BSM::log_random_walk() {
  double call_payoff_pot = 0.0;
  double put_payoff_pot = 0.0;
  double dt = this->get_years() / this->get_steps();
  for (long i = 1; i <= this->get_simulations(); ++i) {
    double spot_price = this->get_asset();
    double cumulative_profit = 0.0;
    for (int j = 1; j <= this->get_steps(); ++j) {
      double epsilon = this->rando();
      double drift = (this->get_growth() -
                      0.5 * this->get_volatility() * this->get_volatility()) *
                     dt;
      double stochastic_term = this->get_volatility() * sqrt(dt) * epsilon;
      // Update the spot price
      spot_price *= exp(drift + stochastic_term);
      std::cout << "Simulation " << i << ", Step " << j
                << ": Asset Price = " << spot_price << std::endl;

      // Calculate and print cumulative profit at each step
      double profit = spot_price - this->get_asset();
      cumulative_profit += profit;
      std::cout << "Simulation " << i << ", Step " << j
                << ": Cumulative Profit = " << cumulative_profit << std::endl;
    }
    // Calculate the call and put option payoffs at the end of the path
    double call_payoff = std::max(spot_price - this->get_strike(), 0.0);
    double put_payoff = std::max(this->get_strike() - spot_price, 0.0);
    call_payoff_pot += call_payoff;
    put_payoff_pot += put_payoff;
  }
  double call_option_price =
      call_payoff_pot / static_cast<double>(this->get_simulations());
  double put_option_price =
      put_payoff_pot / static_cast<double>(this->get_simulations());

  std::cout << "Average Call Option Price: " << call_option_price << std::endl;
  std::cout << "Average Put Option Price: " << put_option_price << std::endl;
}

double BSM::rando() const {
  // Use the Mersenne Twister engine to generate random numbers
  std::mt19937 w = std::mt19937(std::random_device()());
  std::uniform_real_distribution<double> dist(0.0, 1.0);
  return dist(w);
}