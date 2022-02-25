#include "WorldRegionPopulation.h"
const string &WorldRegionPopulation::GetRegion() const {
  return region;
}
void WorldRegionPopulation::SetRegion(const string &new_region) {
  WorldRegionPopulation::region = new_region;
}
const map<int, long long int> &WorldRegionPopulation::GetYearPopulation() const {
  return year_population;
}
void WorldRegionPopulation::SetYearPopulation(const map<int, long long int> &new_year_population) {
  WorldRegionPopulation::year_population = new_year_population;
}
vector<WorldRegionPopulation> WorldRegionPopulation::CalcWorldRegionPopulation(vector<string> &regions,
                                                                               vector<WorldCountry> &world_countries) {
  vector<WorldRegionPopulation> vec{};
  map<int, long long int> tmp{world_countries.at(0).GetYearPopulation()};
  //vector<map> and then result = vector(iter) sum
  for (const auto &item : regions) {
    for (auto &elem : tmp) {
      elem.second = 0;
    }
    for (const auto &w_c : world_countries) {
      if (w_c.GetCountryFeature().GetRegion() == item) {
        //+= operator
        for (auto &element : tmp) {
          element.second += ((w_c.GetYearPopulation().find(element.first) != w_c.GetYearPopulation().end())
                             ? w_c.GetYearPopulation().find(element.first)->second : 0);
        }
      }
    }
    //@TODO logic

    vec.push_back(WorldRegionPopulation(item, tmp));
  }

  return vec;
}
WorldRegionPopulation::WorldRegionPopulation(const string &region, const map<int, long long int> &year_population)
    : region(region), year_population(year_population) {}
WorldRegionPopulation::WorldRegionPopulation() {}
