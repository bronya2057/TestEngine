#pragma comment(lib, "ws2_32.lib")
#include "LoggerAPI.hpp"
#include <winsock2.h>
#include <iostream>
#include <string>

#pragma warning(disable: 4996)

namespace Logger
{
   void LOGGER_API sendMessage(const std::string& messageString);
   void LOGGER_API connectToServer();
}
