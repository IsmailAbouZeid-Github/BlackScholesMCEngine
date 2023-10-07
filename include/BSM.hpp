#pragma once
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

  float get_asset();
  float get_strike();
  float get_growth();
  float get_volatility();
  float get_years();

  long int get_steps();
  long int get_simulations();

  void log_random_walk();

  double get_call_price();
  double get_put_price();
  double rando();

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
};