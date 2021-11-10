#include <memory>
#include "logger/logger.h"


int main(int argc, const char* argv[]) {
  LOG_DEBUG("test");
  LOG_WARN("test");
  LOG_INFO("test");
  LOG_ERROR("test");
  return 0;
}
