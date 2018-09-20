cmake_minimum_required (VERSION 2.8)
include(gtest.cmake)
include_directories(SYSTEM
    ./
)
add_library ( json STATIC 
sources/json.cpp
)
target_include_directories (json 
PUBLIC 
Json3/include
) 

# if(CMAKE_COMPILER_IS_GNUCXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fsanitize=address -O1 -Wall -Wextra -Wno-unused-command-line-argument -Wshadow -Wnon-virtual-dtor -pedantic")
# endif(CMAKE_COMPILER_IS_GNUCXX)

# enum your files
add_executable(json
  test.cpp
)
find_package (Threads)
target_link_libraries (json -fsanitize=address gtest ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (json 
PRIVATE
json) 
