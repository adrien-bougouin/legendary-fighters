#ifndef __MODEL_GAME_ENTITY_TEST_HPP__
#define __MODEL_GAME_ENTITY_TEST_HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../src/models/game_entity.hpp"

class GameEntityTest: public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(GameEntityTest);
  CPPUNIT_TEST(test_initialization);
  CPPUNIT_TEST(test_change_properties);
  CPPUNIT_TEST_SUITE_END();

  public:
    void test_initialization();
    void test_change_properties();
};

CPPUNIT_TEST_SUITE_REGISTRATION(GameEntityTest);

#endif // __MODEL_GAME_ENTITY_TEST_HPP__

