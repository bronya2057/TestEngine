#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>

#pragma warning(disable: 4996)

namespace Logger
{
   void sendMessage(const std::string& messageString);
   void connectToServer();
}
