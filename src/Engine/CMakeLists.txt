set(TARGET_NAME Engine)
set(ENGINE_SRC_DIR ${ENGINE_DIR}/private)

set(
    ENGINE_LIST
    ${ENGINE_DIR}/inc/Engine.hpp
    ${ENGINE_DIR}/inc/Application.hpp
    ${ENGINE_DIR}/inc/Core.hpp
    ${ENGINE_DIR}/inc/EntryPoint.hpp
    ${ENGINE_SRC_DIR}/Application.cpp
    ${ENGINE_SRC_DIR}/platform/WindowsWindow.cpp
)

set(
   EVENTS_LIST
   ${EVENTS_INC_DIR}/MouseEvent.hpp
   ${EVENTS_INC_DIR}/Event.hpp
   ${EVENTS_INC_DIR}/KeyEvent.hpp
   ${EVENTS_INC_DIR}/ApplicationEvent.hpp
   ${EVENTS_INC_DIR}/EventDispatcherAPI.hpp
)

set(
    LOGGER_LIST
    ${LOGGER_INC_DIR}/LoggerAPI.hpp
    ${LOGGER_INC_DIR}/client.hpp
    ${LOGGER_INC_DIR}/CLogger.hpp
    ${LOGGER_INC_DIR}/CConsoleLogger.hpp
    ${LOGGER_SRC_DIR}/client.cpp
    ${LOGGER_SRC_DIR}/CLogger.cpp
    ${LOGGER_SRC_DIR}/CConsoleLogger.cpp
)

set (SOURCE_LIST
     ${ENGINE_LIST}
     ${EVENTS_LIST}
     ${LOGGER_LIST})

add_library(${TARGET_NAME} 
            SHARED 
            ${SOURCE_LIST})

set(INCLUDE_DIRS 
    ${ENGINE_INC_DIR}
    ${SPDLOG_DIR}
    ${GLFW_INC_DIR}
    )

set(LIBRARIES
    GLWF
    opengl32.lib)

target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDE_DIRS})
target_link_libraries(${TARGET_NAME} PRIVATE ${LIBRARIES})

source_group(TREE ${ENGINE_DIR} FILES ${SOURCE_LIST})
add_cotire_lib(${TARGET_NAME})
#add_library(sub::hello ALIAS hello_library)