#include "client.hpp"
#include "CLogger.hpp"

#include <regex>

void CLogger::connect()
{
   Logger::connectToServer();
}

void CLogger::sendMessage(const std::string& message)
{
   Logger::sendMessage(message);
}

CLogger::CLogger()
{
}

const std::string getFileName(std::string fullPath)
{
   std::regex re("(\\w+\\.(cpp|hpp))");
   std::smatch match;
   std::string result;
   if (std::regex_search(fullPath, match, re) && match.size() > 1)
   {
      result = match.str(1);
   }
   else
   {
      result = std::string("");
   }

   return result;
}