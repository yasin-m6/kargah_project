set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.0)
project(c++Project)

add_executable(app src/main.cpp src/peaple.cpp src/passengers.cpp src/air_hostes.cpp src/pilot.cpp src/ticket.cpp src/aireplane.cpp src/mashin_hamle_bar.cpp src/flight.cpp)
include_directories(include)