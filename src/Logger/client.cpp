#include "client.hpp"

namespace Logger
{
   SOCKET Connection;

   void sendMessage(const std::string& messageString) {
      int messageStringSize = messageString.size();
      send(Connection, (char*)&messageStringSize, sizeof(int), NULL);
      send(Connection, messageString.c_str() , messageStringSize, NULL);
      std::cout << messageString << std::endl;
   }

   void connectToServer()
   {
      WSAData wsaData;
      WORD DLLVersion = MAKEWORD(2, 1);
      if (WSAStartup(DLLVersion, &wsaData) != 0) {
         std::cout << "Error" << std::endl;
         exit(1);
      }

      SOCKADDR_IN addr;
      int sizeofaddr = sizeof(addr);
      addr.sin_addr.s_addr = inet_addr("127.0.0.1");
      addr.sin_port = htons(1111);
      addr.sin_family = AF_INET;

      Connection = socket(AF_INET, SOCK_STREAM, NULL);
      if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
         std::cout << "Error: failed connect to server.\n";
      }
      else
      {
         std::cout << "Connected!\n";
      }
   }
}