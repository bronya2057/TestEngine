

namespace Engine
{
   __declspec(dllimport) void printLib();
}

int main()
{
   Engine::printLib();

   return 0;
}