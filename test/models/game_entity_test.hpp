#ifndef __MODELS_GAME_ENTITY_TEST_HPP__
#define __MODELS_GAME_ENTITY_TEST_HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../../src/models/game_entity.hpp"

class GameEntityTest: public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(GameEntityTest);
  CPPUNIT_TEST(test_init);
  CPPUNIT_TEST(test_set_properties);
  CPPUNIT_TEST(test_set_state);
  CPPUNIT_TEST_SUITE_END();

  public:
    void test_init();

    void test_set_properties();
    void test_set_state();
};

CPPUNIT_TEST_SUITE_REGISTRATION(GameEntityTest);

#endif // __MODELS_GAME_ENTITY_TEST_HPP__

