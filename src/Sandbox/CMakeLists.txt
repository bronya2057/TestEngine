set(TARGET_NAME Sandbox)

set(SOURCES
    main.cpp)

add_executable(${TARGET_NAME} ${SOURCES})

target_link_libraries(${TARGET_NAME} 
                      PRIVATE 
                      Engine)