#include "ProgramCountriesPopulation.h"

int ProgramCountriesPopulation::Main() {
  std::cout << "Hello, the stupidest task ever to be made\n";
/*  string line = "AFG;South Asia;Low income;Afghanistan";
  vector<string> vec = ParseString(line, ';');
  for (const auto &item : vec) {
    std::cout << item << " ";
  }*/

  string path{"../data/country_features.csv"};
  vector<CountryFeatures> country_features = ReadCountries(path);

  for (CountryFeatures &country : country_features) {
    std::cout << country << '\n';
  }

  //!Task5
  WorldPopulation world_population{};
  std::string file_path{"../data/world_population_1960-2018.csv"};
  world_population.ReadCountryPopulationFromFile(file_path);
  world_population.CalcWorldPopulation();

  vector<WorldCountry> world_country{ReadCountryPopulationFromFile(world_population, country_features)};
  std::cout << "Size of new vector = " << world_country.size();

  vector<string> regions = CountryFeatures::GetUniqueRegions(country_features);
  std::cout << "\nSize of regions vector = " << regions.size();

  //!Task10
  vector<WorldRegionPopulation>
      world_region_population = WorldRegionPopulation().CalcWorldRegionPopulation(regions, world_country);
  std::cout << "\nSize of regions population vector = " << world_region_population.size();
  std::cout << "\n" << world_region_population.at(0).GetRegion();//.GetYearPopulation().find(2010)->second;

  string file_path_out{"../data/output.txt"};
  WriteWorldRegionPopulationToFile(file_path_out, world_region_population);

  return 0;
}

vector<CountryFeatures> ProgramCountriesPopulation::ReadCountries(string &path) {
  vector<CountryFeatures> vec{};
  std::ifstream fin{};
  fin.open(path);

  if (fin.is_open()) {
    string line{};
    vector<string> line_elements{};
    while (!fin.eof()) {
      std::getline(fin, line);
      line_elements = ParseString(line, ';');
      vec.push_back(CountryFeatures(line_elements.at(0), line_elements.at(1), line_elements.at(2)));
    }
  } else { std::cout << "File is unreachable"; }
  fin.close();

  return vec;
}

/*vector<WorldCountry> ProgramCountriesPopulation::ReadCountryPopulationFromFile(string &file) {
//!WorldPopulation.year_population = WorldCountry.year_population && etc.
  vector<WorldCountry> vec{};

  for (const auto &item : vec) {

  }

  return vec;
}*/
vector<WorldCountry> ProgramCountriesPopulation::ReadCountryPopulationFromFile(WorldPopulation &world_population,
                                                                               vector<CountryFeatures> &country_features) {
  vector<WorldCountry> vec{};
  CountryFeatures tmp{};
  for (const auto &item : world_population.GetCountries()) {
    for (const auto &feature : country_features) {
      if (feature.GetCountryCode() == item.country_code) {
        tmp = feature;
      }
    }
    vec.push_back(WorldCountry(item.country_name, tmp, item.year_population));
  }

  return vec;
}
void ProgramCountriesPopulation::WriteWorldRegionPopulationToFile(string &file,
                                                                  vector<WorldRegionPopulation> &world_region_population) {
  std::ofstream fout{};
  fout.open(file);

  if (fout.is_open()) {
    fout << world_region_population.at(0).GetRegion();
    for (const auto &item : world_region_population.at(0).GetYearPopulation()) {
      fout << "\t" << item.first;
    }
    for (const auto &population : world_region_population) {
      if (population.GetRegion() != "Region") {
        fout << population.GetRegion();
        for (const auto &item1 : population.GetYearPopulation()) {
          fout << "\t" << item1.second;
        }
      }
      fout << "\n";
    }
  } else { std::cout << "File is unreachable"; }

  fout.close();

}
