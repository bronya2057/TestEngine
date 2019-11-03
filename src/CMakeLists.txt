set(PROJECT_SOURCE_DIR   ${CMAKE_CURRENT_SOURCE_DIR})
set(ENGINE_DIR           ${PROJECT_SOURCE_DIR}/Engine)
set(LOGGER_DIR           ${PROJECT_SOURCE_DIR}/Logger)
set(EVENTS_DIR           ${PROJECT_SOURCE_DIR}/EventDispatcher)
set(SPDLOG_DIR           ${PROJECT_SOURCE_DIR}/Logger/vendor/spdlog/include)

set(EVENTS_INC_DIR       ${EVENTS_DIR}/inc)
set(ENGINE_INC_DIR       ${ENGINE_DIR}/inc)
set(LOGGER_INC_DIR       ${LOGGER_DIR}/inc)

add_subdirectory(EventDispatcher)
add_subdirectory(Logger)
add_subdirectory(Engine)
add_subdirectory(Sandbox)