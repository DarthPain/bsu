#include "CountryFeatures.h"
const string &CountryFeatures::GetCountryCode() const {
  return country_code;
}
void CountryFeatures::SetCountryCode(const string &new_country_code) {
  CountryFeatures::country_code = new_country_code;
}
const string &CountryFeatures::GetRegion() const {
  return region;
}
void CountryFeatures::SetRegion(const string &new_region) {
  CountryFeatures::region = new_region;
}
const string &CountryFeatures::GetIncomeGroup() const {
  return income_group;
}
void CountryFeatures::SetIncomeGroup(const string &new_income_group) {
  CountryFeatures::income_group = new_income_group;
}
CountryFeatures::CountryFeatures(const string &country_code, const string &region, const string &income_group)
    : country_code(country_code), region(region), income_group(income_group) {}
CountryFeatures::CountryFeatures() {}

string CountryFeatures::ToString() const {
  return std::string{country_code + " " + region + " " + income_group};;
}
std::ostream &operator<<(std::ostream &os, const CountryFeatures &features) {
  os << "country_code: " << features.country_code << " region: " << features.region << " income_group: "
     << features.income_group;
  return os;
}
vector<string> CountryFeatures::GetUniqueRegions(vector<CountryFeatures> &countries) {
  vector<string> vec{};
  vector<string>::iterator iter{};
  for (const auto &country : countries) {
    iter = std::find(vec.begin(), vec.end(), country.region);
    if (iter == vec.end()) {
      vec.push_back(country.region);
    }
  }
  return vec;
}
vector<CountryFeatures> CountryFeatures::GetCountriesByRegion(vector<CountryFeatures> &countries, string &find_region) {
  vector<CountryFeatures> vec{};
  for (const auto &country : countries) {
    if (country.region == find_region) {
      vec.push_back(country);
    }
  }
  return vec;
}
