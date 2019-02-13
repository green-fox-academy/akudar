cmake_minimum_required(VERSION 3.13)
project(Klassz)

set(CMAKE_CXX_STANDARD 14)

add_executable(Klassz main.cpp Restaurant.cpp Restaurant.h Employees.cpp Employees.h Waiter.cpp Waiter.h Chef.cpp Chef.h Manager.cpp Manager.h)