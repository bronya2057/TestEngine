#include "Application.hpp"

#include "ApplicationEvent.hpp"

#include <CConsoleLogger.hpp>
#include <CLogger.hpp>

namespace Engine
{

Application::Application()
{
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
   
}

}//namespace Engine
