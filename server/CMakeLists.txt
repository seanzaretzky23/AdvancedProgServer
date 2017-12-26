cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES_SERVER mainServer.cpp Server.cpp Server.h ReadFile.cpp ReadFile.h Command.h PrintCommand.cpp PrintCommand.h CommandsManager.h CommandsManager.cpp)
add_executable(RunServer ${SOURCE_FILES_SERVER})