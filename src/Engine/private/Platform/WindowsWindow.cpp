#include "platform/WindowsWindow.hpp"
#include "Logger/CConsoleLogger.hpp"

namespace Engine {

   static uint8_t s_GLFWWindowCount = 0;

   Window* Window::Create(const WindowProps& props)
   {
      return new WindowsWindow(props);
   }

   WindowsWindow::WindowsWindow(const WindowProps& props)
   {
      Init(props);
   }

   WindowsWindow::~WindowsWindow()
   {
      Shutdown();
   }

   void WindowsWindow::Init(const WindowProps& props)
   {
      m_Data.Title = props.Title;
      m_Data.Width = props.Width;
      m_Data.Height = props.Height;

      ENGINE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

      if (s_GLFWWindowCount == 0)
      {
         ENGINE_CORE_INFO("Initializing GLFW");
         int success = glfwInit();
         ENGINE_CORE_ASSERT(success, "Could not intialize GLFW!");
         //glfwSetErrorCallback(GLFWErrorCallback);
      }

      mWindow = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
      ++s_GLFWWindowCount;
   }

   void WindowsWindow::Shutdown()
   {
      glfwDestroyWindow(mWindow);

      if (--s_GLFWWindowCount == 0)
      {
         ENGINE_CORE_INFO("Terminating GLFW");
         glfwTerminate();
      }
   }

   void WindowsWindow::OnUpdate()
   {
      glfwPollEvents();
      glfwSwapBuffers(mWindow);
   }

   void WindowsWindow::SetVSync(bool enabled)
   {
      if (enabled)
         glfwSwapInterval(1);
      else
         glfwSwapInterval(0);

      m_Data.VSync = enabled;
   }

   bool WindowsWindow::IsVSync() const
   {
      return m_Data.VSync;
   }

}
