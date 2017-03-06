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
  const Vector2D vector = Vector2D(1.0, 2.0);

  CPPUNIT_ASSERT(vector == Vector2D(1.0, 2.0));
  CPPUNIT_ASSERT(!(vector == Vector2D(2.0, 1.0)));
}

void Vector2DTest::test_not_equal() {
  const Vector2D vector = Vector2D(1.0, 2.0);

  CPPUNIT_ASSERT(!(vector != Vector2D(1.0, 2.0)));
  CPPUNIT_ASSERT(vector != Vector2D(2.0, 1.0));
}

void Vector2DTest::test_scalar_multiplication() {
  Vector2D vector = Vector2D(1.0, 2.0);
  Vector2D result = vector * 3.0;

  CPPUNIT_ASSERT(result == Vector2D(3.0, 6.0));
}

void Vector2DTest::test_negative_scalar_multiplication() {
  Vector2D vector = Vector2D(1.0, 2.0);
  Vector2D result = vector * -3.0;

  CPPUNIT_ASSERT(result == Vector2D(-3.0, -6.0));
}

void Vector2DTest::test_translation() {
  Vector2D vector = Vector2D(1.0, 2.0);

  vector += Vector2D(3.0, 6.0);

  CPPUNIT_ASSERT(vector == Vector2D(4.0, 8.0));
}

void Vector2DTest::test_negative_translation() {
  Vector2D vector = Vector2D(1.0, 2.0);

  vector -= Vector2D(3.0, 6.0);

  CPPUNIT_ASSERT(vector == Vector2D(-2.0, -4.0));
}

