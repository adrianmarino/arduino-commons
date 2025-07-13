#include "Logger.h"

Logger logger(9600);

Logger::Logger(unsigned long baud, LogLevel level)
{
    Serial.begin(baud);
    setLevel(level); 
    while (!Serial && millis() < 5000)
        ;
}

void Logger::setLevel(LogLevel level) {
    this->level = level;
}

void Logger::log(LogLevel level, String msg) {
  if (level >= this->level) {
    switch (level) {
      case TRACE:
        Serial.print("[TRACE] ");
        break;
      case DEBUG:
        Serial.print("[DEBUG] ");
        break;
      case INFO:
        Serial.print("[INFO] ");
        break;
      case WARN:
        Serial.print("[WARN] ");
        break;
      case ERROR:
        Serial.print("[ERROR] ");
        break;
      case FATAL:
        Serial.print("[FATAL] ");
        break;
    }
    Serial.println(msg);
  }
}

// 4. Funciones auxiliares para mayor facilidad de uso
void Logger::trace(String msg) {
  log(TRACE, msg);
}

void Logger::debug(String msg) {
  log(DEBUG, msg);
}

void Logger::info(String msg) {
  log(INFO, msg);
}

void Logger::warn(String msg) {
  log(WARN, msg);
}

void Logger::error(String msg) {
  log(ERROR, msg);
}

void Logger::fatal(String msg) {
  log(FATAL, msg);
}

void Logger::debugPlot(String varName, float value) {
  if (LogLevel::DEBUG >= level) {
    Serial.println(">" + varName + ":" + String(value)); 
  }
}