set(TARGET_NAME Engine)

add_library(${TARGET_NAME} 
            SHARED 
            test.cpp)
            
#add_library(sub::hello ALIAS hello_library)