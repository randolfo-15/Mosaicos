#Composição da lib Display :

 add_subdirectory(tema)

 add_subdirectory(printable)

 add_subdirectory(display)
 
 add_library(mosaico STATIC "")
 
 #add_custom_target(a ALL COMMAND cmake -E echo "$<INSTALL_INTERFACE:Randolfo>")
 
 set_target_properties(mosaico
    PROPERTIES
        POSITION_INDEPENDENT_CODE  1
        SOVERSION ${PROJECT_VERSION_MAJOR}
        OUTPUT_NAME "Mosaico"
        DEBUG_POSTFIX "_d"
)

 target_link_libraries(mosaico PRIVATE tema printable display)
