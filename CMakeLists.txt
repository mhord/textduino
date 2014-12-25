project (textduino)
add_library (dynamic_item dynamic_item.cpp)
add_library (room room.cpp)
add_executable (textduino main.cpp)
target_link_libraries (textduino dynamic_item room)

