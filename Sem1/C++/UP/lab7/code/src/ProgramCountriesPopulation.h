#include "WorldCountry.h"
#include "WorldPopulation.h"
#include "WorldRegionPopulation.h"

#ifndef CLION_SRC_PROGRAMCOUNTRIESPOPULATION_H_
#define CLION_SRC_PROGRAMCOUNTRIESPOPULATION_H_

class ProgramCountriesPopulation {
 private:
  static vector<CountryFeatures> ReadCountries(string &path);

 public :
  static int Main();
  static vector<WorldCountry> ReadCountryPopulationFromFile(string &file);
  static vector<WorldCountry> ReadCountryPopulationFromFile(WorldPopulation &, vector<CountryFeatures> &);
  static void WriteWorldRegionPopulationToFile(string &file, vector<WorldRegionPopulation> &);

};

#endif //CLION_SRC_PROGRAMCOUNTRIESPOPULATION_H_
