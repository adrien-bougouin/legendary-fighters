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

bool Vector2D::operator==(const Vector2D &vector) const {
  return x_ == vector.x() && y_ == vector.y();
}

bool Vector2D::operator!=(const Vector2D &vector) const {
  return !(*this == vector);
}

Vector2D Vector2D::operator*(const double &scalar) const {
  return Vector2D(x_ * scalar, y_ * scalar);
}

void Vector2D::operator+=(const Vector2D &vector) {
  x_ += vector.x();
  y_ += vector.y();
}

void Vector2D::operator-=(const Vector2D &vector) {
  x_ -= vector.x();
  y_ -= vector.y();
}

