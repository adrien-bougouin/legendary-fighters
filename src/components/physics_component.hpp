#ifndef __COMPONENTS_PHYSICS_COMPONENT_HPP
#define __COMPONENTS_PHYSICS_COMPONENT_HPP

class GameEntity;

class PhysicsComponent {
  private:
    double max_x_velocity_;
    double max_y_velocity_;
    double x_acceleration_;
    double y_acceleration_;
  public:
    // TODO
    //PhysicsComponent(const double &max_velocity, const double &acceleration);
    PhysicsComponent();

    void update(GameEntity &game_entity);

    void stop_horizontal_motion(GameEntity &game_entity);
    void stop_vertical_motion(GameEntity &game_entity);

    void move_left(GameEntity &game_entity);
    void move_right(GameEntity &game_entity);
    void jump(GameEntity &game_entity);
};

#endif // __COMPONENTS_PHYSICS_COMPONENT_HPP

