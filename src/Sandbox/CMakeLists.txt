set(TARGET_NAME Sandbox)

set(SOURCES
    main.cpp)

add_executable(${TARGET_NAME} ${SOURCES})

target_link_libraries(${TARGET_NAME} 
                      PRIVATE 
                      Engine)

set(INCLUDE_DIRS 
    ${ENGINE_INC_DIR}
    ${SPDLOG_DIR}
    )

target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDE_DIRS})

add_cotire_lib(${TARGET_NAME})