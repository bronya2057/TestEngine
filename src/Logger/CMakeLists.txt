set(TARGET_NAME Logger)
set(LOGGER_SRC_DIR ${LOGGER_DIR}/private)

set(
    SOURCE_LIST
    ${LOGGER_INC_DIR}/LoggerAPI.hpp
    ${LOGGER_INC_DIR}/client.hpp
    ${LOGGER_INC_DIR}/CLogger.hpp
    ${LOGGER_INC_DIR}/CConsoleLogger.hpp
    ${LOGGER_SRC_DIR}/client.cpp
    ${LOGGER_SRC_DIR}/CLogger.cpp
    ${LOGGER_SRC_DIR}/CConsoleLogger.cpp
)

add_library(${TARGET_NAME} 
            SHARED 
            ${SOURCE_LIST})

set(INCLUDE_DIRS 
    ${LOGGER_INC_DIR}
    ${SPDLOG_DIR}
    )

target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDE_DIRS})

source_group(TREE ${LOGGER_DIR} FILES ${SOURCE_LIST})

#add_library(sub::hello ALIAS hello_library)