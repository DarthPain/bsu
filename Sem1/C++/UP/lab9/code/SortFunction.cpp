//
// Created by Roman on 12/15/2019.
//

#include "SortFunction.h"
#include "old/Containers.h"
#include "Circle.h"
#include "Sector.h"

std::vector<std::string> SortFunction::ReadInfo(std::string &path) {
  std::ifstream fin{};
  fin.open(path);
  std::vector<std::string> objects{};
  if (fin.is_open()) {
    std::string info{};
    std::getline(fin, info);
    int n = std::stoi(info);
    std::getline(fin, info);
    std::string sort_type = info;
    for (int i = 0; i < n; ++i) {
      std::getline(fin, info);
      objects.push_back(info);
    }
    objects.push_back(sort_type);
  } else {
    throw 2;
  }
  fin.close();
  return objects;
}

void SortFunction::WriteInfo(std::string &path, BiDirectionalList<Shape3d *> &figures) {
  std::ofstream fout{};
  fout.open(path);
  if (fout.is_open()) {
    for (int i = 0; i < figures.Size(); ++i) {
      fout << figures[i]->value->toString() << "\n";
    }
  } else {
    throw 1;
  }
  fout.close();
}

void SortFunction::SortAll(std::string &file_in, std::string &file_out) {
  try {
    std::vector<std::string> objects = ReadInfo(file_in);
    BiDirectionalList<Shape3d *> figures = Sort(objects);
    WriteInfo(file_out, figures);
  } catch (int) {
    std::cerr << "File problems!\n";
    exit(-1);
  } catch (...) {
    std::cerr << "Something went wrong!\n";
    exit(-3);
  }

}

BiDirectionalList<Shape3d *> SortFunction::Sort(std::vector<std::string> &objects) {
  int sort_type = std::stoi(objects[objects.size() - 1]);
  objects.pop_back();
  BiDirectionalList<Shape3d *> figures{};
  Shape3d *shape{};
  for (auto &item : objects) {
    if (isFigure(item)) {
      Shape3d *shape1 = toFigure(item);
      figures.PushBack(shape1);
    }
  }
  switch (sort_type) {
    case SORTTYPE_PERIMETER:
      for (int i = 0; i < figures.Size(); ++i) {
        for (int j = i; j < figures.Size(); ++j) {
          if (figures[j]->value->perimeter() < figures[i]->value->perimeter()) {
            shape = figures[j]->value;
            figures[j]->value = figures[i]->value;
            figures[i]->value = shape;
          }
        }
      }
      break;
    case SORTTYPE_VOLUME:
      for (int i = 0; i < figures.Size(); ++i) {
        for (int j = i; j < figures.Size(); ++j) {
          if (figures[i]->value->volume() > figures[j]->value->volume()) {
            shape = figures[j]->value;
            figures[j]->value = figures[i]->value;
            figures[i]->value = shape;
          }
        }
      }
      break;
    default: std::cout << "Something went wrong!\n";
  }
  return figures;
}

bool SortFunction::isFigure(std::string line) {
  bool flag = true;
  std::string word{wordFromString(line, ' ')};
  int figure_type{std::stoi(word)};
  switch (figure_type) {
    case TYPES_BASIC:if (!line.empty()) { flag = false; }
      break;
    case TYPES_CIRCLE:word = wordFromString(line, ' ');
      if (!isNumber(word)) { flag = false; }
      if (!line.empty()) { flag = false; }
      break;
    case TYPES_SECTOR:word = wordFromString(line, ' ');
      if (!isNumber(word)) { flag = false; }
      word = wordFromString(line, ' ');
      if (!isNumber(word)) { flag = false; }
      if (!line.empty()) { flag = false; }
      break;
    default: flag = false;
  }
  return flag;
}

Shape3d *SortFunction::toFigure(std::string &line) {
  std::string word{wordFromString(line, ' ')};
  std::string word1{};
  int figure_type{std::stoi(word)};
  auto *shape = new Shape3d();
  switch (figure_type) {
    case TYPES_BASIC:break;
    case TYPES_CIRCLE:word = wordFromString(line, ' ');
      shape = new Circle(std::stoi(word));
      break;
    case TYPES_SECTOR:word = wordFromString(line, ' ');
      word1 = wordFromString(line, ' ');
      shape = new Sector(std::stoi(word), std::stoi(word1));
      break;
    default: break;
  }
  return shape;
}

std::string SortFunction::wordFromString(std::string &line, char delim) {
  if (line.empty() || line.at(line.size() - 1) != delim) { line.push_back(delim); }
  std::string word{line.substr(0, line.find(delim))};
  line = line.substr(line.find(delim) + 1);
  return word;
}

bool SortFunction::isNumber(std::string &line) {
  bool flag = true;
  for (const auto &item : line) {
    if (!((int) item < 58 || item == '.' || item == '-')) {
      flag = false;
    }
  }
  return flag;
}
