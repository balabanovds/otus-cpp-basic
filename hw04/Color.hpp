#pragma once

#include <istream>
class Color {
public:
  Color();
  Color(double red, double green, double blue);
  double red() const;
  double green() const;
  double blue() const;

private:
  double r{};
  double g{};
  double b{};
};

inline std::istream &operator>>(std::istream &is, Color &c) {
  double r, g, b;
  is >> r >> g >> b;
  Color tmp(r, g, b);
  c = tmp;

  return is;
}
