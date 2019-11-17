#include "Application.hpp"

#include "Events/ApplicationEvent.hpp"

#include "Logger/CConsoleLogger.hpp"
#include "Logger/CLogger.hpp"

namespace Engine
{

Application::Application()
{
   mWindow = std::unique_ptr<Window>(Window::Create());
}

Application::~Application()
{
}

void Application::run()
{
   EventDispatcher::WindowResizeEvent e(1024, 840);
   ENGINE_CORE_TRACE(e.ToString().c_str())

   CLogger::connect();
   LOG("%s", e.ToString().c_str());
   ENGINE_CORE_INFO("fweq");
   while (mRunning)
   {
      mWindow->OnUpdate();
   }
}

}//namespace Engine
