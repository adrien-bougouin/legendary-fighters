#ifndef __COMPONENTS_FRAME_DATA_COMPONENT_HPP__
#define __COMPONENTS_FRAME_DATA_COMPONENT_HPP__

class GameEntity;

class FrameDataComponent {
  public:
    void update(GameEntity &game_entity);
    void goto_next_frame(GameEntity &game_entity);
};

#endif // __COMPONENTS_FRAME_DATA_COMPONENT_HPP__

