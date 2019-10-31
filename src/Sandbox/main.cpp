#include <Engine.hpp>
#include <CLogger.hpp>


class Sandbox : public Engine::Application
{
public:
   Sandbox()
   {

   }

   ~Sandbox()
   {

   }
};

Engine::Application* Engine::createApplication()
{
   CLogger::connect();
   CLogger::sendMessage("Hello how are you");
   return new Sandbox();
}