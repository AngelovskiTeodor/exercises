cmake_minimum_required(VERSION 3.5)

project(8 LANGUAGES C)

add_executable(8 main.c)

include(GNUInstallDirs)
install(TARGETS 8
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
