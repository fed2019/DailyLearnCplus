cmake_minimum_required(VERSION 3.5)

project(DailyLearnCplus LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O2 -Wall")

set(CURRENT_PROJECT_PATH ${PROJECT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CURRENT_PROJECT_PATH}/output)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package (Threads REQUIRED)

add_executable(thread_param1 src/thread_param1.cpp)
target_link_libraries(thread_param1
    -lpthread
)

add_executable(thread_param2 src/thread_param2.cpp)
target_link_libraries(thread_param2
    -lpthread
)

add_executable(thread_param src/thread_param.cpp)
target_link_libraries(thread_param
    -lpthread
)

add_executable(vector_test src/vector_test.cpp)
target_link_libraries(vector_test
    -lpthread
)