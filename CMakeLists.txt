cmake_minimum_required(VERSION 3.29)
project(ServerFinanceMgr)

set(CMAKE_CXX_STANDARD 20)

add_executable(ServerFinanceMgr main.cpp
        ServerHardware.cpp
        ServerHardware.h
        StorageHardware.cpp
        StorageHardware.h
        utils.h
)
