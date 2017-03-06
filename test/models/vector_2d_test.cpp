#include "vector_2d_test.hpp"

void Vector2DTest::test_init() {
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

void Vector2DTest::test_equal() {
  const double x = 1.0;
  const double y = 2.0;
  const Vector2D vector = Vector2D(x, y);

  CPPUNIT_ASSERT(vector == Vector2D(1.0, 2.0));
  CPPUNIT_ASSERT(!(vector == Vector2D(2.0, 1.0)));
}

void Vector2DTest::test_not_equal() {
  const double x = 1.0;
  const double y = 2.0;
  const Vector2D vector = Vector2D(x, y);

  CPPUNIT_ASSERT(!(vector != Vector2D(1.0, 2.0)));
  CPPUNIT_ASSERT(vector != Vector2D(2.0, 1.0));
}

void Vector2DTest::test_translation() {
  const double x = 1.0;
  const double y = 2.0;
  const double inc_x = 3.0;
  const double inc_y = 6.0;
  Vector2D vector = Vector2D(x, y);

  vector += Vector2D(inc_x, inc_y);

  CPPUNIT_ASSERT(vector == Vector2D(x + inc_x, y + inc_y));
}

void Vector2DTest::test_negative_translation() {
  const double x = 1.0;
  const double y = 2.0;
  const double dec_x = 3.0;
  const double dec_y = 6.0;
  Vector2D vector = Vector2D(x, y);

  vector -= Vector2D(dec_x, dec_y);

  CPPUNIT_ASSERT(vector == Vector2D(x - dec_x, y - dec_y));
}

