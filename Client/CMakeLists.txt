cmake_minimum_required(VERSION 3.0.0)
project(Client VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Client 
    src/main.c
    src/Controller/controller.h
    src/Controller/controller.c
    src/Controller/hello_world_controller.h
    src/Controller/hello_world_controller.c
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME} curl)