cmake_minimum_required(VERSION 3.16)

project(oliovk2kotiteht LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(oliovk2kotiteht main.cpp
    game.h game.cpp)

include(GNUInstallDirs)
install(TARGETS oliovk2kotiteht
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
