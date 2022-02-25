#include <iostream>
#include "gtest/gtest.h"
#include "Shape3d.h"
#include "Circle.h"
#include "Sector.h"
#include "old/Containers.h"
#include <cmath>
#include "SortFunction.h"

long long int Shape::id_base = 0;

TEST (Shapes_tests, creation_tests) {
  Shape shape{};
  EXPECT_EQ(TYPES_BASIC, shape.getType());
  EXPECT_EQ(1, shape.getId());
  EXPECT_EQ(std::string{"Id = 1; Type = 0"}, shape.toString());

  int type_cooler_basic{7};
  Shape shape1{type_cooler_basic};
  EXPECT_EQ(7, shape1.getType());
  EXPECT_EQ(2, shape1.getId());
  EXPECT_EQ(std::string{"Id = 2; Type = 7"}, shape1.toString());

  Shape2d shape2d{};
  EXPECT_EQ(TYPES_BASIC, shape2d.getType());
  EXPECT_EQ(3, shape2d.getId());
  EXPECT_EQ(std::string{"Id = 3; Type = 0; Perimeter = 0"}, shape2d.toString());

  Shape2d shape2d1{type_cooler_basic};
  EXPECT_EQ(7, shape2d1.getType());
  EXPECT_EQ(4, shape2d1.getId());
  EXPECT_EQ(std::string{"Id = 4; Type = 7; Perimeter = 0"}, shape2d1.toString());

  Shape3d shape3d{};
  EXPECT_EQ(TYPES_BASIC, shape3d.getType());
  EXPECT_EQ(5, shape3d.getId());
  EXPECT_EQ(std::string{"Id = 5; Type = 0; Perimeter = 0; Volume = 0"}, shape3d.toString());

  Shape3d shape3d1{type_cooler_basic};
  EXPECT_EQ(7, shape3d1.getType());
  EXPECT_EQ(6, shape3d1.getId());
  EXPECT_EQ(std::string{"Id = 6; Type = 7; Perimeter = 0; Volume = 0"}, shape3d1.toString());
}

TEST (Circle_tests, basic_tests) {
  Circle circle{};
  EXPECT_EQ(7, circle.getId());
  EXPECT_EQ(TYPES_CIRCLE, circle.getType());
  EXPECT_EQ(0, circle.perimeter());
  EXPECT_EQ(0, circle.area());

  Circle circle1{10};
  EXPECT_EQ(8, circle1.getId());
  EXPECT_EQ(TYPES_CIRCLE, circle1.getType());
  EXPECT_LT(abs(20 * 3.1416 - circle1.perimeter()), 0.01 * circle1.getRadius());
  EXPECT_LT(abs(314.16 - circle1.area()), 0.01 * circle1.getRadius());
}

TEST (Sector_tests, basic_tests) {
  Sector sector{};
  EXPECT_EQ(9, sector.getId());
  EXPECT_EQ(TYPES_SECTOR, sector.getType());
  EXPECT_EQ(0, sector.perimeter());
  EXPECT_EQ(0, sector.area());

  Sector sector1{10};
  EXPECT_EQ(10, sector1.getId());
  EXPECT_EQ(TYPES_SECTOR, sector1.getType());
  EXPECT_LT(abs(20 * 3.1416 + 20 - sector1.perimeter()), 0.01 * sector1.getRadius());
  EXPECT_LT(abs(314.16 - sector1.area()), 0.01 * sector1.getRadius());

  Sector sector2{10, 3.1416 / 2};
  EXPECT_EQ(11, sector2.getId());
  EXPECT_EQ(TYPES_SECTOR, sector2.getType());
  EXPECT_LT(abs(20 * 3.1416 / 4 + 20 - sector2.perimeter()), 0.01 * sector2.getRadius());
  EXPECT_LT(abs(314.16 / 4 - sector2.area()), 0.01 * sector2.getRadius());
}

TEST (BiDiList_tests, basic_tests) {

  BiDirectionalList<int> bi_di_list{};
  bi_di_list.PushBack(7);
  EXPECT_EQ(7, bi_di_list.Back()->value);
  EXPECT_EQ(7, bi_di_list.Front()->value);
  bi_di_list.PopFront();
  EXPECT_EQ(nullptr, bi_di_list.Front());
  EXPECT_EQ(nullptr, bi_di_list.Back());

  BiDirectionalList<Shape3d *> bi_di_list_shapes{};
  Circle circle{-10};
  Sector sector{10, -3.1416 / 2};
  bi_di_list_shapes.PushBack(&circle);
  bi_di_list_shapes.PushBack(&sector);
  EXPECT_EQ(TYPES_CIRCLE, bi_di_list_shapes.Front()->value->getType());
  EXPECT_EQ(TYPES_SECTOR, bi_di_list_shapes.Back()->value->getType());
  EXPECT_EQ(TYPES_SECTOR, bi_di_list_shapes[1]->value->getType());
  EXPECT_EQ(20 * M_PI, bi_di_list_shapes[0]->value->perimeter());
}

TEST (Main_function_tests, all_tests) {
  std::string out{"../data/output.txt"};
  std::string in{"../data/input.txt"};
  SortFunction::SortAll(in, out);
}


