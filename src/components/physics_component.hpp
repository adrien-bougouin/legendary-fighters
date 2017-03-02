#ifndef __COMPONENTS_PHYSICS_COMPONENT_HPP
#define __COMPONENTS_PHYSICS_COMPONENT_HPP

class GameEntity;

class PhysicsComponent {
  public:
    // TODO
    //PhysicsComponent(const double &max_velocity, const double &acceleration);
    PhysicsComponent();

    void update(GameEntity &game_entity);
};

#endif // __COMPONENTS_PHYSICS_COMPONENT_HPP

