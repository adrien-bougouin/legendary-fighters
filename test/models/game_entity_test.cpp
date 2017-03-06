#include "game_entity_test.hpp"
#include "../../src/states/state.hpp"
#include "../../src/states/standing_state.hpp"
#include "../../src/states/jumping_state.hpp"

void GameEntityTest::test_init() {
  const GameEntity game_entity = GameEntity();

  CPPUNIT_ASSERT(game_entity.direction() == 1.0);
  CPPUNIT_ASSERT(game_entity.position().x() == 0.0);
  CPPUNIT_ASSERT(game_entity.position().y() == 0.0);
  CPPUNIT_ASSERT(game_entity.velocity().x() == 0.0);
  CPPUNIT_ASSERT(game_entity.velocity().y() == 0.0);

  CPPUNIT_ASSERT(game_entity.state() == &AState::standing_state);
}

void GameEntityTest::test_set_properties() {
  GameEntity game_entity = GameEntity();

  game_entity.set_direction(-1.0);
  game_entity.position().set_x(1.0);
  game_entity.position().set_y(2.0);
  game_entity.velocity().set_x(3.0);
  game_entity.velocity().set_y(4.0);

  CPPUNIT_ASSERT(game_entity.direction() == -1.0);
  CPPUNIT_ASSERT(game_entity.position().x() == 1.0);
  CPPUNIT_ASSERT(game_entity.position().y() == 2.0);
  CPPUNIT_ASSERT(game_entity.velocity().x() == 3.0);
  CPPUNIT_ASSERT(game_entity.velocity().y() == 4.0);
}

void GameEntityTest::test_set_state() {
  GameEntity game_entity = GameEntity();

  game_entity.set_state(&AState::jumping_state);

  CPPUNIT_ASSERT(game_entity.state() == &AState::jumping_state);
}

