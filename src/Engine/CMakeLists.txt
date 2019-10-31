set(TARGET_NAME Engine)


add_library(${TARGET_NAME} 
            SHARED 
            ${EngineDir}/Engine/Application.cpp)

#add_library(sub::hello ALIAS hello_library)