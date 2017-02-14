#include <chrono>

#include "time.hpp"

double utils::time::milliseconds_since_epoch() {
  using ms_double = std::chrono::duration<double, std::chrono::milliseconds::period>;

  return ms_double(std::chrono::system_clock::now().time_since_epoch()).count();
}

