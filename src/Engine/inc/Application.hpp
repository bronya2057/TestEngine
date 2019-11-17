#pragma once

#include <memory>

#include "Core.hpp"
#include "Window.hpp"

namespace Engine
{

class ENGINE_API Application
{
public:
   Application();
   virtual ~Application();
   void run();

private:
   std::unique_ptr<Window> mWindow;
   bool mRunning = true;
};

//To be defined in client
Application* createApplication();

}//namespace Engine