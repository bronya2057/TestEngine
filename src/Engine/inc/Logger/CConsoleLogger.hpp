#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "LoggerAPI.hpp"

namespace spdlog
{
   class logger;
}

namespace Logger
{

class LOGGER_API CConsoleLogger
{
public:
   CConsoleLogger();
   ~CConsoleLogger();
   static void init();

   static std::shared_ptr<spdlog::logger>& getCoreLogger();
   static std::shared_ptr<spdlog::logger>& getClientLogger();

private:
   static std::shared_ptr<spdlog::logger> sCoreLogger;
   static std::shared_ptr<spdlog::logger> sClientLogger;
};

#define ENGINE_CORE_TRACE(...) ::Logger::CConsoleLogger::getCoreLogger()->trace(__VA_ARGS__);
#define ENGINE_CORE_INFO(...) ::Logger::CConsoleLogger::getCoreLogger()->info(__VA_ARGS__);
#define ENGINE_CORE_WARN(...) ::Logger::CConsoleLogger::getCoreLogger()->warn(__VA_ARGS__);
#define ENGINE_CORE_ERROR(...) ::Logger::CConsoleLogger::getCoreLogger()->error(__VA_ARGS__);
#define ENGINE_CORE_FATAL(...) ::Logger::CConsoleLogger::getCoreLogger()->fatal(__VA_ARGS__);

#define ENGINE_CLIENT_TRACE(...) ::Logger::CConsoleLogger::getClientLogger()->trace(__VA_ARGS__);
#define ENGINE_CLIENT_INFO(...) ::Logger::CConsoleLogger::getClientLogger()->info(__VA_ARGS__);
#define ENGINE_CLIENT_WARN(...) ::Logger::CConsoleLogger::getClientLogger()->warn(__VA_ARGS__);
#define ENGINE_CLIENT_ERROR(...) ::Logger::CConsoleLogger::getClientLogger()->error(__VA_ARGS__);
#define ENGINE_CLIENT_FATAL(...) ::Logger::CConsoleLogger::getClientLogger()->fatal(__VA_ARGS__);

}//namespace Logger
