cmake_minimum_required(VERSION 3.5)

project(01-4 LANGUAGES C)

add_executable(01-4 main.c)

include(GNUInstallDirs)
install(TARGETS 01-4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
