cmake_minimum_required(VERSION 3.16)

project(Vk4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Vk4 main.cpp
    asiakas.cpp asiakas.h CMakeLists.txt luottotili.cpp luottotili.h main.cpp pankkitili.cpp pankkitili.h)

include(GNUInstallDirs)
install(TARGETS Vk4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
