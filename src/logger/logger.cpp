#include "logger.h"
#include <assert.h>

Logger::Logger(bool debug) : m_debug(debug) {}

const char* Logger::levelToText(Level level) {
  switch (level) {
    case Level::DEBUG:
      return "DEBUG";
      break;
    case Level::INFO:
      return "INFO";
      break;
    case Level::WARN:
      return "WARN ";
      break;
    case Level::ERROR:
      return "ERROR";
      break;
    default:
      // Should not happen
      assert(false);
      break;
  }
}

void Logger::log(const char* text, Level level) {
  if (!m_debug && level == Level::DEBUG)
    return;

  static const char* WHITE = "\033[0m";
  const char* color = WHITE;
  switch (level) {
    case Level::DEBUG:
      color = "\x1B[32m";  // GREEN
      break;
    case Level::INFO:
      color = "\x1B[34m";  // BLUE
      break;
    case Level::WARN:
      color = "\x1B[33m";  // YELLOW
      break;
    case Level::ERROR:
      color = "\x1B[31m";  // RED
      break;
    default:
      break;
  }

  std::cout << color << "[ " << levelToText(level) << " ] " << WHITE << text
            << std::endl;
}