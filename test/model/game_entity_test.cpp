#include "game_entity_test.hpp"

void GameEntityTest::test_initialization() {
  const GameEntity game_entity = GameEntity();

  CPPUNIT_ASSERT(game_entity.position().x() == 0.0);
  CPPUNIT_ASSERT(game_entity.position().y() == 0.0);
  CPPUNIT_ASSERT(game_entity.velocity().x() == 0.0);
  CPPUNIT_ASSERT(game_entity.velocity().y() == 0.0);
}

void GameEntityTest::test_change_properties() {
  GameEntity game_entity = GameEntity();

  game_entity.position().set_x(1.0);
  game_entity.position().set_y(2.0);
  game_entity.velocity().set_x(3.0);
  game_entity.velocity().set_y(4.0);

  CPPUNIT_ASSERT(game_entity.position().x() == 1.0);
  CPPUNIT_ASSERT(game_entity.position().y() == 2.0);
  CPPUNIT_ASSERT(game_entity.velocity().x() == 3.0);
  CPPUNIT_ASSERT(game_entity.velocity().y() == 4.0);
}

