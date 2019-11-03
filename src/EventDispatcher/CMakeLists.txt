set(TARGET_NAME EventDispatcher)

set(
    SOURCE_LIST
    ${EVENTS_INC_DIR}/MouseEvent.hpp
    ${EVENTS_INC_DIR}/Event.hpp
    ${EVENTS_INC_DIR}/KeyEvent.hpp
    ${EVENTS_INC_DIR}/ApplicationEvent.hpp
    ${EVENTS_INC_DIR}/EventDispatcherAPI.hpp
)



add_library(${TARGET_NAME} 
            SHARED 
            ${SOURCE_LIST})

set_target_properties(${TARGET_NAME}  PROPERTIES LINKER_LANGUAGE CXX)

source_group(TREE ${EVENTS_DIR} FILES ${SOURCE_LIST})

#add_library(sub::hello ALIAS hello_library)