#include "Rectangle.h"
#include "Util.h"
Rectangle::Rectangle() {}

double Rectangle::IntersectionArea(Rectangle &a, Rectangle &b) {
  //Conditions
  double left_side_a{a.left_up.GetX()};
  double left_side_b{b.left_up.GetX()};
  double right_side_a{b.right_bottom.GetX()};
  double right_side_b{b.right_bottom.GetX()};

  double top_side_a{a.left_up.GetY()};
  double top_side_b{b.left_up.GetY()};
  double bot_side_a{a.right_bottom.GetY()};
  double bot_side_b{b.right_bottom.GetY()};

  Point new_left_top{Util::Max(left_side_a, left_side_b), Util::Min(top_side_a, top_side_b)};
  Point new_right_bot{Util::Min(right_side_a, right_side_b), Util::Max(bot_side_a, bot_side_b)};
//  std::cout << "LT : " << new_left_top.GetX() << " " << new_left_top.GetY() << "\n";
//  std::cout << "Rb : " << new_right_bot.GetX() << " " << new_right_bot.GetY() << "\n";

  return Rectangle{new_left_top, new_right_bot}.Area();
}
double Rectangle::Area() {
  return abs(left_up.GetX() - right_bottom.GetX()) * abs(left_up.GetY() - right_bottom.GetY());
}

Rectangle::Rectangle(const Point &current_left_up, const Point &current_right_bottom) {
  if (current_left_up.GetX() < current_right_bottom.GetX() && current_left_up.GetY() > current_right_bottom.GetY()) {
    left_up = current_left_up;
    right_bottom = current_right_bottom;
  } else {
    std::cout
        << "Second point should be lower and farther then 1st!!!(default same coords)\n";
    right_bottom.SetX(left_up.GetX());
    right_bottom.SetY(left_up.GetY());
  }
}


