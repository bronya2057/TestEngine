set(TARGET_NAME Logger)

add_library(${TARGET_NAME} 
            SHARED 
            client.cpp
            CLogger.cpp)

#add_library(sub::hello ALIAS hello_library)