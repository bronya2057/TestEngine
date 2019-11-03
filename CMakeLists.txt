cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project (TestEngine LANGUAGES CXX)

include(GNUInstallDirs)
set(binFolder $<$<CONFIG:Debug>:cmakeDebug>$<$<CONFIG:Release>:cmakeRelease>)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_INSTALL_LIBDIR}/${binFolder})
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_INSTALL_BINDIR}/${binFolder})

add_subdirectory(src)

#add_custom_command(TARGET TestEngine POST_BUILD
#  COMMAND ${CMAKE_COMMAND} -E echo 
#  "target dir = $<TARGET_FILE_DIR:TestEngine>")

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
   target_compile_definitions(Sandbox PUBLIC "ENGINE_WIN")
   target_compile_definitions(Engine PUBLIC "ENGINE_WIN")
   target_compile_definitions(Logger PUBLIC "ENGINE_WIN")
   target_compile_definitions(EventDispatcher PUBLIC "ENGINE_WIN")
endif()


if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(Engine PUBLIC "ENGINE_BUILD_DLL")
  target_compile_definitions(Logger PUBLIC "ENGINE_BUILD_DLL")
  target_compile_definitions(EventDispatcher PUBLIC "ENGINE_BUILD_DLL")
endif()


message("SOURCES: ${SOURCES}")
message("SOURCES: ${SOURCES}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")