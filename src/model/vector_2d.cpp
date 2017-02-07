#include "vector_2d.hpp"

Vector2D::Vector2D(const double &x, const double &y): x_(x), y_(y) {
}

const double &Vector2D::x() const {
  return x_;
}

const double &Vector2D::y() const {
  return y_;
}

void Vector2D::set_x(const double &x) {
  x_ = x;
}

void Vector2D::set_y(const double &y) {
  y_ = y;
}

