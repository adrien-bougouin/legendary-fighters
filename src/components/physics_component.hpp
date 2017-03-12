#ifndef __COMPONENTS_PHYSICS_COMPONENT_HPP
#define __COMPONENTS_PHYSICS_COMPONENT_HPP

class GameEntity;

class PhysicsComponent {
  public:
    void update(GameEntity &game_entity);
};

#endif // __COMPONENTS_PHYSICS_COMPONENT_HPP

