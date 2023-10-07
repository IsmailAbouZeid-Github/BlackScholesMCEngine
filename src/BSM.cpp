#include "BSM.hpp"

BSM::BSM(constructorArgs &args) {
  this->_asset = args.asset;
  this->_strike = args.strike;
  this->_volatility = args.volatility;
  this->_growth = args.growth;
  this->_years = args.years;
  this->_steps = args.steps;
  this->_simulations = args.simulations;
}
float BSM::get_asset() { return this->_asset; }
float BSM::get_strike() { return this->_strike; }
float BSM::get_volatility() { return this->_volatility; }
float BSM::get_growth() { return this->_growth; }
float BSM::get_years() { return this->_years; }

long int BSM::get_steps() { return this->_steps; }
long int BSM::get_simulations() { return this->_simulations; }

double BSM::get_call_price() { return this->_call_price; }
double BSM::get_put_price() { return this->_put_price; }

void BSM::log_random_walk() {}

double BSM::rando() { return 0.0; }