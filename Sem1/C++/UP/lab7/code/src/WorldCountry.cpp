#include "WorldCountry.h"

WorldCountry::WorldCountry() {}
WorldCountry::WorldCountry(string country_name,
                           CountryFeatures country_feature,
                           map<int, long long int> year_population)
    : country_name(std::move(country_name)),
      country_feature(std::move(country_feature)),
      year_population(std::move(year_population)) {}
const string &WorldCountry::GetCountryName() const {
  return country_name;
}
void WorldCountry::SetCountryName(const string &new_country_name) {
  WorldCountry::country_name = new_country_name;
}
const CountryFeatures &WorldCountry::GetCountryFeature() const {
  return country_feature;
}
void WorldCountry::SetCountryFeature(const CountryFeatures &new_country_feature) {
  WorldCountry::country_feature = new_country_feature;
}
const map<int, long long int> &WorldCountry::GetYearPopulation() const {
  return year_population;
}
void WorldCountry::SetYearPopulation(const map<int, long long int> &new_year_population) {
  WorldCountry::year_population = new_year_population;
}
vector<WorldCountry> WorldCountry::GetCountryByIncomeLevel(vector<WorldCountry>& init, string& income_level) {
  vector<WorldCountry> vec{};
  for (const auto &item : init) {
    if (item.country_feature.GetIncomeGroup() == income_level) {
      vec.push_back(item);
    }
  }
  return vec;
}