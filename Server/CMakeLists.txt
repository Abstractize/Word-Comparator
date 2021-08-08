cmake_minimum_required(VERSION 3.17.2)
project(Server VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Server 
    src/main.c
    src/API/routes.h
    src/API/routes.c
    src/API/hello_world_controller.h
    src/API/hello_world_controller.c
    )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME} ulfius)