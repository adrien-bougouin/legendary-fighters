#ifndef __MODEL_VECTOR_2D_TEST_HPP__
#define __MODEL_VECTOR_2D_TEST_HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../src/model/vector_2d.hpp"

class Vector2DTest: public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(Vector2DTest);
  CPPUNIT_TEST(test_initialization);
  CPPUNIT_TEST(test_set_x);
  CPPUNIT_TEST(test_set_y);
  CPPUNIT_TEST_SUITE_END();

  public:
    void test_initialization();
    void test_set_x();
    void test_set_y();
};

CPPUNIT_TEST_SUITE_REGISTRATION(Vector2DTest);

#endif // __MODEL_VECTOR_2D_TEST_HPP__

