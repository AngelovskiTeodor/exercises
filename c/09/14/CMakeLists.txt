cmake_minimum_required(VERSION 3.5)

project(14 LANGUAGES C)

add_executable(14 main.c)

include(GNUInstallDirs)
install(TARGETS 14
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
