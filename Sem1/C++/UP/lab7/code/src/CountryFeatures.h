#include <string>
#include <ostream>
#include <vector>

using std::string;
using std::vector;
#ifndef CLION_SRC_COUNTRYFEATURES_H_
#define CLION_SRC_COUNTRYFEATURES_H_

class CountryFeatures {
 private:
  string country_code;
  string region;
  string income_group;

 public:
  CountryFeatures(const string &country_code, const string &region, const string &income_group);
  CountryFeatures();

  const string &GetCountryCode() const;
  void SetCountryCode(const string &new_country_code);
  const string &GetRegion() const;
  void SetRegion(const string &new_region);
  const string &GetIncomeGroup() const;
  void SetIncomeGroup(const string &new_income_group);

  string ToString() const;

  static vector<string> GetUniqueRegions(vector<CountryFeatures> &countries);
  vector<CountryFeatures> GetCountriesByRegion(vector<CountryFeatures> &countries, string &find_region);

  friend std::ostream &operator<<(std::ostream &os, const CountryFeatures &features);
};

#endif //CLION_SRC_COUNTRYFEATURES_H_
