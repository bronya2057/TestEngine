#pragma once

#include <string>
#include "LoggerAPI.hpp"

#define TOSTRING(x) STRINGIFY(x)
#define STRINGIFY(x) #x
#define MESSAGE(str, ...) tfm::format(str, __VA_ARGS__);
#define TM_PRINTF(f_, ...) printf((f_), ##__VA_ARGS__);

const std::string getFileName(std::string fullPath);

#define LOG(f_, ...) {char buffer[2048]; \
                      snprintf(buffer, sizeof(buffer), f_, ##__VA_ARGS__);\
                      std::string str;\
                      std::string fileName(TOSTRING(__FILE__));\
                      str.append("[");\
                      str.append(getFileName(fileName));\
                      str.append("]");\
                      str.append(" (");\
                      str.append(__FUNCTION__);\
                      str.append(") ");\
                      str.append(buffer);\
                      str.append(" => ");\
                      str.append(TOSTRING(__LINE__));\
                      CLogger::sendMessage(str);\
                      std::cout<<buffer;}

#define LOG_CALL() LOG("")

class LOGGER_API CLogger
{
public:
   static void connect();
   static void sendMessage(const std::string& message);

   CLogger();
   CLogger(const CLogger& handler) = delete;
   bool operator==(const CLogger& handler) = delete;
   CLogger(const CLogger&& handler) = delete;
   bool operator==(const CLogger&& handler) = delete;
};