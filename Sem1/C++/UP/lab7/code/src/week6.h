/*
#include "WorldCountry.h"
#ifndef CLION_SRC_WEEK6_H_
#define CLION_SRC_WEEK6_H_

std::string WordFromString(std::string &line);

struct Country {
  Country(std::string &name, std::string &code, std::map<int, long long int> &y_pop) {
    country_name = name;
    country_code = code;
    year_population = y_pop;
  }

  Country() {}

  std::string country_name;
  std::string country_code;
  std::map<int, long long int> year_population;

  std::string ToString() {
    std::string result{country_name + " (" + country_code + ") : "};
    for (const auto &item : year_population) {
      result += std::to_string(item.second) + "[" + std::to_string(item.first) + "], ";
    }
    return result;
  }

};

struct WorldPopulation {
  std::vector<Country> countries;
  std::map<int, long long int> year_population;

  void ReadCountryPopulationFromFile(std::string &file) {
    std::ifstream fin{};
    fin.open(file);
    if (fin.is_open()) {
      std::string line{};
      std::string current_value;
      std::getline(fin, line);
      //First initializer country
      countries.push_back(GetInitCountry(line));
      auto it = countries.at(0).year_population.begin();
      std::string country_name{};
      std::string country_code{};
      std::map<int, long long int> year_population_country{};
      while (!fin.eof()) {
        std::getline(fin, line);
        //fill countries
        if (line.empty() && fin.eof()) { break; }
        if (line.at(line.length() - 1) != ';') {
          line += ";";
        }
        current_value = WordFromString(line);
        country_name = current_value;
        line = line.substr(current_value.length() + 1);
        current_value = WordFromString(line);
        country_code = current_value;
        line = line.substr(current_value.length() + 1);
        it = countries.at(0).year_population.begin();
        while (it != countries.at(0).year_population.end()) {
          current_value = WordFromString(line);
          line = line.substr(current_value.length() + 1);
          year_population_country.insert(std::pair<int, long long int>(it->first,
                                                                       ((current_value.empty())
                                                                        ? 0 : std::stoi(current_value))));
          it++;
        }
        countries.emplace_back(country_name, country_code, year_population_country);
        year_population_country.clear();
      }

    } else {
      std::cout << "File is unreachable";
    }
  }

  Country GetInitCountry(std::string &line) {
    if (line.at(line.length() - 1) != ';') {
      line += ";";
    }
    std::string current_value{WordFromString(line)};
    std::string country_name = current_value;
    line = line.substr(current_value.length() + 1);
    current_value = WordFromString(line);
    std::string country_code = current_value;
    line = line.substr(current_value.length() + 1);
    std::map<int, long long int> year_population_country{};
    while (line.length() > 2) {
      current_value = WordFromString(line);
      line = line.substr(current_value.length() + 1);
      year_population_country.insert(std::pair<int, long long int>(std::stoi(current_value), 0));
    }
    return Country(country_name, country_code, year_population_country);
  }

  void CalcWorldPopulation() {
    */
/*long long int sum{0};
    auto it = year_population.begin();
    int i = 0;
    for (const auto &country : countries) {
      while (it == year_population.end()) {
        std::cout << "Am I here ";
        sum += country.year_population.at(it->first);
        it++;
      }
      it = year_population.begin();
      for (int j = 0; j < i; ++j) {
        it++;
      }
      year_population.at(it->first) = sum;
      ++i;
      ++it;
    }*//*


    long long int sum{};
    long long int sum_all{};
    for (int i = 1960; i < 2019; ++i) {
      for (const auto &country : countries) {
        if (country.country_name != "Country Name") {
          sum += country.year_population.at(i);
          sum_all += sum;
        }
      }
      year_population.insert({i, sum});
      year_population.insert({0, sum_all});
      sum = 0;
    }

  }

  void print() {
    std::string out{};
    for (Country country : countries) {
      out = country.ToString();
      out = out.substr(0, out.length() - 2);
      std::cout << out << "\n\n\n";
    }
  }

  void printPopulation() {
    for (const auto &item : year_population) {
      std::cout << item.second << "[" << item.first << "], ";
    }
  }

  //@TODO make it beautiful and according to the task!!!
  void PrintFile(std::string &file_path) {
    std::fstream fout{};
    fout.open(file_path);
    if (fout.is_open()) {
      std::string out{};
      for (Country country : countries) {
        out = country.ToString();
        out = out.substr(0, out.length() - 2);
        fout << out << "\n";
      }
    } else { std::cout << "File is unreachable"; }
  }
};

*/
/*!int main() {

  WorldPopulation world_population{};
  std::string file_path{"../data/world_population_1960-2018.csv"};
  world_population.ReadCountryPopulationFromFile(file_path);
//  world_population.print();
  world_population.CalcWorldPopulation();
//  world_population.printPopulation();
  std::string file_path_out{"../data/out.txt"};
  world_population.PrintFile(file_path_out);
  return 0;
}*//*


std::string WordFromString(std::string &line) {
  int ind_break{0};
  for (int i = 0; i < line.length(); ++i) {
    if (line.at(i) == ';') {
      ind_break = i;
      break;
    }
  }

  return (line.length() == 1) ? line : line.substr(0, ind_break);
}

#endif //CLION_SRC_WEEK6_H_
*/
