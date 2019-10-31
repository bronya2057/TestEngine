set(TARGET_NAME Sandbox)

set(SOURCES
    main.cpp)

add_executable(${TARGET_NAME} ${SOURCES})

target_link_libraries(${TARGET_NAME} 
                      PRIVATE 
                      Engine
                      Logger)

set(INCLUDE_DIRS 
    ${EngineDir}
    ${LoggerDir}
    )
message(${INCLUDE_DIRS})
target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDE_DIRS})