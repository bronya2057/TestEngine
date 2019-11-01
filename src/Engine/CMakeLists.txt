set(TARGET_NAME Engine)
set(ENGINE_SRC_DIR ${ENGINE_DIR}/private)

set(
    SOURCE_LIST
    ${ENGINE_DIR}/inc/Engine.hpp
    ${ENGINE_DIR}/inc/Application.hpp
    ${ENGINE_DIR}/inc/Core.hpp
    ${ENGINE_DIR}/inc/EntryPoint.hpp
    ${ENGINE_SRC_DIR}/Application.cpp
)

add_library(${TARGET_NAME} 
            SHARED 
            ${SOURCE_LIST})

set(INCLUDE_DIRS 
    ${LOGGER_INC_DIR}
    ${ENGINE_INC_DIR}
    ${SPDLOG_DIR}
    )

target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDE_DIRS})

source_group(TREE ${ENGINE_DIR} FILES ${SOURCE_LIST})

#add_library(sub::hello ALIAS hello_library)