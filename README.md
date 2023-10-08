# BlackScholesMCEngine
# Black-Scholes Monte Carlo Option Pricing

This project implements a Monte Carlo simulation for option pricing based on the Black-Scholes model. The simulation estimates the prices of European call and put options.

## Project Structure

- **BSM.hpp**: Header file containing the class definition and constructorArgs structure.
- **BSM.cpp**: Source file implementing the methods of the BSM class.
- **main.cpp**: Main program that initializes the BSM object, runs the simulation, and prints the results.
- **CMakeLists.txt**: CMake configuration file for building the project.

## Class Structure

### BSM Class

The BSM (Black-Scholes-Merton) class represents the Monte Carlo simulation for option pricing. It includes the following methods:

- `BSM(constructorArgs &args)`: Constructor to initialize the BSM object with the given parameters.
- `~BSM()`: Destructor.
- `float get_asset() const`: Get the initial asset price.
- `float get_strike() const`: Get the strike price.
- `float get_volatility() const`: Get the volatility.
- `float get_growth() const`: Get the growth rate.
- `float get_years() const`: Get the time to maturity in years.
- `long int get_steps() const`: Get the number of time steps.
- `long int get_simulations() const`: Get the number of simulations.
- `double get_call_price()`: Get the call option price.
- `double get_put_price()`: Get the put option price.
- `void log_random_walk()`: Perform the Monte Carlo simulation.
- `double rando() const`: Generate a random number in the range [0, 1].

### constructorArgs Structure

The `constructorArgs` structure holds the input parameters required for the simulation. It includes:

- `float asset`: Initial asset price.
- `float strike`: Strike price of the option.
- `float growth`: Growth rate of the asset.
- `float volatility`: Volatility of the asset.
- `float years`: Time to maturity in years.
- `int steps`: Number of time steps.
- `int simulations`: Number of simulation runs.

## Discretized Monte Carlo Formula

The discretized Monte Carlo simulation is based on the Black-Scholes model. The key formula used for simulating the asset price path is:

S_t+1 = S_t * exp((r - (σ^2) / 2) * Δt + σ * √Δt * ε)

Where:
- `S_t` is the asset price at time `t`.
- `S_t+1` is the asset price at the next time step.
- `r` is the risk-free interest rate.
- `σ` is the volatility of the asset.
- `Δt` is the time step size (time to maturity divided by the number of steps).
- `ε` is a random number drawn from a standard normal distribution.

This formula is used to update the asset price at each time step within the simulation.
## Running the Program

To run the program, use the following command-line arguments:
./main <asset> <strike> <growth> <volatility> <years> <steps> <simulations>
Replace `<asset>`, `<strike>`, `<growth>`, `<volatility>`, `<years>`, `<steps>`, and `<simulations>` with the desired values for your option pricing simulation.



