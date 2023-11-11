cmake_minimum_required(VERSION 3.5)

project(11 LANGUAGES C)

add_executable(11 main.c)

include(GNUInstallDirs)
install(TARGETS 11
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
