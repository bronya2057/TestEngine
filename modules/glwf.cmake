SET(TARGET_NAME GLWF)
SET(GLWF_DIR ${CMAKE_SOURCE_DIR}/src/Engine/vendor/glfw)
SET(GLWF_INC_DIR ${GLWF_DIR}/include/GLFW)

    set(GLFW_source
        ${GLWF_DIR}/src/context.c
        ${GLWF_DIR}/src/egl_context.c
        ${GLWF_DIR}/src/init.c
        ${GLWF_DIR}/src/input.c
        ${GLWF_DIR}/src/monitor.c
        ${GLWF_DIR}/src/osmesa_context.c
        ${GLWF_DIR}/src/vulkan.c
        ${GLWF_DIR}/src/wgl_context.c
        ${GLWF_DIR}/src/win32_init.c
        ${GLWF_DIR}/src/win32_joystick.c
        ${GLWF_DIR}/src/win32_monitor.c
        ${GLWF_DIR}/src/win32_thread.c
        ${GLWF_DIR}/src/win32_time.c
        ${GLWF_DIR}/src/win32_window.c
        ${GLWF_DIR}/src/window.c
    )
    
    set(includes
        ${GLWF_INC_DIR}/glfw3.h
        ${GLWF_INC_DIR}/glfw3native.h)

set (SOURCE_LIST
     ${GLFW_source}
     ${includes})

add_library(${TARGET_NAME} STATIC ${SOURCE_LIST})

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
   target_compile_definitions(${TARGET_NAME} PUBLIC "_GLFW_WIN32")
   target_compile_definitions(${TARGET_NAME} PUBLIC "_CRT_SECURE_NO_WARNINGS")
endif()

target_include_directories(${TARGET_NAME} PRIVATE ${GLWF_INC_DIR})

source_group(TREE ${GLWF_DIR} FILES ${SOURCE_LIST})