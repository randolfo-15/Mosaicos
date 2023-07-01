#Construção lib Display :

 set(MY_PATH "${CMAKE_SOURCE_DIR}/include")
                                                                
#Display:
add_library(Dp_stc STATIC display.cpp printables.cpp tema.cpp)  
target_include_directories(Dp_stc PUBLIC ${MY_PATH})
                                                                
