#include <iostream>
#include <string>
#include "../config.h"

class Logger {
 public:
  enum class Level { DEBUG, INFO, WARN, ERROR };
  Logger(bool debug);

  void log(const char* text, Level level = Level::DEBUG);

 private:
  bool m_debug;
  static const char* levelToText(Level level);
};

static std::shared_ptr<Logger> GLOBAL_LOGGER =
    std::shared_ptr<Logger>(new Logger(DEBUGGING));

#define LOG(text, level) GLOBAL_LOGGER->log(text, level)
#define LOG_DEBUG(text) LOG(text, Logger::Level::DEBUG)
#define LOG_INFO(text) LOG(text, Logger::Level::INFO)
#define LOG_WARN(text) LOG(text, Logger::Level::WARN)
#define LOG_ERROR(text) LOG(text, Logger::Level::ERROR)