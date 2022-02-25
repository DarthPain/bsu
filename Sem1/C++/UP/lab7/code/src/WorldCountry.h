#include <iostream>
#include "Util.h"
#include "Util.cpp"
#include "CountryFeatures.h"
#include <fstream>
#include <map>

using std::map;

#ifndef CLION_SRC_WORLDCOUNTRY_H_
#define CLION_SRC_WORLDCOUNTRY_H_

class WorldCountry {
 private:
  string country_name;
  CountryFeatures country_feature;
  map<int, long long int> year_population;

 public:
  WorldCountry();
  WorldCountry(string country_name,
               CountryFeatures country_feature,
               map<int, long long int> year_population);

  const string &GetCountryName() const;
  void SetCountryName(const string &new_country_name);
  const CountryFeatures &GetCountryFeature() const;
  void SetCountryFeature(const CountryFeatures &new_country_feature);
  const map<int, long long int> &GetYearPopulation() const;
  void SetYearPopulation(const map<int, long long int> &new_year_population);

  vector<WorldCountry> GetCountryByIncomeLevel(vector<WorldCountry> &init_vec, string &income_level);

};

#endif //CLION_SRC_WORLDCOUNTRY_H_
