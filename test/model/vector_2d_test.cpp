#include "vector_2d_test.hpp"

void Vector2DTest::test_initialization() {
  const double x = 1.0;
  const double y = 2.0;
  const Vector2D vector = Vector2D(x, y);

  CPPUNIT_ASSERT(vector.x() == x);
  CPPUNIT_ASSERT(vector.y() == y);
}

void Vector2DTest::test_set_x() {
  const double x = 1.0;
  const double y = 2.0;
  const double new_x = 3.0;
  Vector2D vector = Vector2D(x, y);

  vector.set_x(new_x);

  CPPUNIT_ASSERT(vector.x() == new_x);
  CPPUNIT_ASSERT(vector.y() == y);
}

void Vector2DTest::test_set_y() {
  const double x = 1.0;
  const double y = 2.0;
  const double new_y = 3.0;
  Vector2D vector = Vector2D(x, y);

  vector.set_y(new_y);

  CPPUNIT_ASSERT(vector.x() == x);
  CPPUNIT_ASSERT(vector.y() == new_y);
}

