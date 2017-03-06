#ifndef __MODELS_INPUT_TEST_HPP__
#define __MODELS_INPUT_TEST_HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../src/models/input.hpp"

class InputTest: public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(InputTest);
  CPPUNIT_TEST(test_init);
  CPPUNIT_TEST_SUITE_END();

  public:
    void test_init();
};

CPPUNIT_TEST_SUITE_REGISTRATION(InputTest);

#endif // __MODELS_INPUT_TEST_HPP__

