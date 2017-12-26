cmake_minimum_required(VERSION 3.8)
project(AdvancedProgServer)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")

add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES_SERVER Server.cpp Server.h ReadFile.cpp ReadFile.h StrCommand.h StrCommand.cpp Command.h PrintCommand.cpp PrintCommand.h CommandsManager.h CommandsManager.cpp)
set(TEST_FILES tests/StrCommand_Test.cpp)

add_executable(RunServer ${SOURCE_FILES_SERVER} mainServer.cpp)
add_executable(tests ${SOURCE_FILES} ${TEST_FILES} tests/gtest_main.cpp)

target_link_libraries(tests gtest gtest_main pthread)
target_link_libraries(RunServer gtest gtest_main pthread)
add_test(test test)
