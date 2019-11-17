set(PROJECT_SOURCE_DIR   ${CMAKE_CURRENT_SOURCE_DIR})
set(ENGINE_DIR           ${PROJECT_SOURCE_DIR}/Engine)
set(VENDOR_DIR           ${ENGINE_DIR}/vendor)
set(SPDLOG_DIR           ${VENDOR_DIR}/spdlog/include)

set(ENGINE_INC_DIR       ${ENGINE_DIR}/inc)
set(ENGINE_PRIVATE_DIR   ${ENGINE_DIR}/private)

set(EVENTS_INC_DIR ${ENGINE_INC_DIR}/Events)
set(LOGGER_INC_DIR ${ENGINE_INC_DIR}/Logger)

set(EVENTS_SRC_DIR ${ENGINE_PRIVATE_DIR}/Events)
set(LOGGER_SRC_DIR ${ENGINE_PRIVATE_DIR}/Logger)
set(GLFW_INC_DIR   ${VENDOR_DIR}/glfw/include)

add_subdirectory(Engine)
add_subdirectory(Sandbox)