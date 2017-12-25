cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES_SERVER mainServer.cpp Server.cpp Server.h ReadFile.cpp ReadFile.h)
set(SOURCE_FILES_CLIENT Client.cpp Client.h mainClient.cpp)
add_executable(RunServer ${SOURCE_FILES_SERVER})
add_executable(RunCLient ${SOURCE_FILES_CLIENT})