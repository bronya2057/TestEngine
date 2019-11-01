#pragma once

#ifdef ENGINE_WIN

extern Engine::Application* Engine::createApplication();

int main(int argc, char** argv)
{
   auto app = Engine::createApplication();

   Logger::CConsoleLogger::init();
   Logger::CConsoleLogger::getCoreLogger()->warn("core warning");
   Logger::CConsoleLogger::getClientLogger()->info("core warning");

   ENGINE_CORE_TRACE("Warn")

   CLogger::connect();
   CLogger::sendMessage("Hello how are you");

   app->run();

   delete app;

   return 0;
}
#endif