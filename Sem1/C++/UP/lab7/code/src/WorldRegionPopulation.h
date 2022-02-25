#include <map>
#include <string>
#include <vector>
#include "WorldCountry.h"

using std::vector;
using std::map;
using std::string;

#ifndef CLION_SRC_WORLDREGIONPOPULATION_H_
#define CLION_SRC_WORLDREGIONPOPULATION_H_

class WorldRegionPopulation {
 private:
  string region;
  map<int, long long int> year_population;
 public:
  WorldRegionPopulation();
 public:
  WorldRegionPopulation(const string &region, const map<int, long long int> &year_population);

 public:
  const string &GetRegion() const;
  void SetRegion(const string &new_region);
  const map<int, long long int> &GetYearPopulation() const;
  void SetYearPopulation(const map<int, long long int> &new_year_population);

  vector<WorldRegionPopulation> CalcWorldRegionPopulation(vector<string> &, vector<WorldCountry> &);

};

#endif //CLION_SRC_WORLDREGIONPOPULATION_H_
