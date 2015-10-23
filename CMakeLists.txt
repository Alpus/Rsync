cmake_minimum_required(VERSION 3.2)
project(Rsync)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Rsync ${SOURCE_FILES} Hashers/md5.h Hashers/md5.cpp Classes/FileManager.cpp Classes/FileManager.h)