#pragma once
#include <cmath>

#include "Color.hpp"
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
  Ball(const Velocity &velocity, const Point &center, const double &radius,
       const Color &color, const bool isCollidable) {
    this->velocity = velocity;
    this->center = center;
    this->radius = radius;
    this->color = color;
    this->isCollidable = isCollidable;

    // We calculate mass ones as radius is also constant.
    this->mass = M_PI * std::pow(this->radius, 3) * 4. / 3.;
  }
  void setVelocity(const Velocity &velocity);
  Velocity getVelocity() const;
  void draw(Painter &painter) const;
  void setCenter(const Point &center);
  Point getCenter() const;
  double getRadius() const;
  double getMass() const;
  bool getIsCollidable() const;

private:
  Velocity velocity;
  Point center;
  double radius;
  Color color;
  bool isCollidable;
  double mass;
};
