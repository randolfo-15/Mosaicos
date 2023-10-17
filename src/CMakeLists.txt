#Composição da lib Display :

 add_subdirectory(tema)

 add_subdirectory(printable)

 add_subdirectory(display)
 
 add_library(mosaico STATIC "")
 
 target_link_libraries(mosaico PRIVATE tema printable display)
