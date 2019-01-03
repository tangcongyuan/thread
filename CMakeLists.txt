cmake_minimum_required (VERSION 2.6)
project (Thread)

# append flag, best practice, suggested, don't lose previously defined flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# using c++ 17
set(CMAKE_CXX_STANDARD 17)

include_directories(include/)
file(GLOB SOURCE src/*.cpp)
add_executable(exec ${SOURCE})

find_package(Threads)
target_link_libraries(exec ${CMAKE_THREAD_LIBS_INIT})
