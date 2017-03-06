#include "input_test.hpp"

void InputTest::test_init() {
  Input input = Input(InputType::QUIT, InputMethod::OTHER);

  CPPUNIT_ASSERT(input.type == InputType::QUIT);
  CPPUNIT_ASSERT(input.method == InputMethod::OTHER);
}

