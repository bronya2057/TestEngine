#include "Logger/CConsoleLogger.hpp"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Logger
{

LOGGER_API std::shared_ptr<spdlog::logger> CConsoleLogger::sCoreLogger;
LOGGER_API std::shared_ptr<spdlog::logger> CConsoleLogger::sClientLogger;

Logger::CConsoleLogger::CConsoleLogger()
{
}

Logger::CConsoleLogger::~CConsoleLogger()
{
}

void Logger::CConsoleLogger::init()
{
   spdlog::set_pattern("%^[%T] %n: %v%$");
   sCoreLogger = spdlog::stdout_color_mt("Engine");
   sCoreLogger->set_level(spdlog::level::trace);

   sClientLogger = spdlog::stdout_color_mt("APP");
   sClientLogger->set_level(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger>& Logger::CConsoleLogger::getCoreLogger() { return sCoreLogger; }
std::shared_ptr<spdlog::logger>& Logger::CConsoleLogger::getClientLogger() { return sClientLogger; }

}//namespace Logger


