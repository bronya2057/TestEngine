#pragma once

#ifdef ENGINE_WIN

extern Engine::Application* Engine::createApplication();

int main(int argc, char** argv)
{
   Logger::CConsoleLogger::init();
   Logger::CConsoleLogger::getCoreLogger()->warn("core warning");
   Logger::CConsoleLogger::getClientLogger()->info("core warning");

   auto app = Engine::createApplication();

   ENGINE_CORE_TRACE("Warn")
   ENGINE_CORE_TRACE("Warn2")

   //CLogger::connect();
   //CLogger::sendMessage("Hello how are you");

   app->run();

   delete app;

   return 0;
}
#endif