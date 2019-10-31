set(PROJECT_SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR})
set(EngineDir           ${PROJECT_SOURCE_DIR}/Engine)
set(LoggerDir           ${PROJECT_SOURCE_DIR}/Logger)

add_subdirectory(Engine)
add_subdirectory(Sandbox)
add_subdirectory(Logger)