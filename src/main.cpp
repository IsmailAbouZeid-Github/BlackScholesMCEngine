#include "BSM.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 8) {
    std::cerr << "Usage: " << argv[0]
              << " <asset> <strike> <growth> <volatility> <years> <steps> "
                 "<simulations>"
              << std::endl;
    return 1;
  }

  // Parse command-line arguments
  float asset = atof(argv[1]);
  float strike = atof(argv[2]);
  float growth = atof(argv[3]);
  float volatility = atof(argv[4]);
  float years = atof(argv[5]);
  int steps = atoi(argv[6]);
  int simulations = atoi(argv[7]);

  // Create constructorArgs structure
  constructorArgs cargs;
  cargs.asset = asset;
  cargs.strike = strike;
  cargs.growth = growth;
  cargs.volatility = volatility;
  cargs.years = years;
  cargs.steps = steps;
  cargs.simulations = simulations;

  // Create BSM object
  BSM bsm(cargs);

  // Run the simulation
  bsm.log_random_walk();

  return 0;
}
