#pragma once
#include <cmath>
#include <iostream>
#include <random>
struct constructorArgs {
  float asset;
  float strike;
  float growth;
  float volatility;
  float years;

  int steps;
  int simulations;
};
class BSM {
public:
  BSM(constructorArgs &args);
  ~BSM();

  float get_asset() const;
  float get_strike() const;
  float get_growth() const;
  float get_volatility() const;
  float get_years() const;

  long int get_steps() const;
  long int get_simulations() const;

  void log_random_walk();

  double get_call_price();
  double get_put_price();
  double rando() const;

private:
  float _asset;
  float _strike;
  float _growth;
  float _volatility;
  float _years;

  long int _steps;
  long int _simulations;

  double _call_price;
  double _put_price;

  std::mt19937 _mt_engine;
};