cmake_minimum_required(VERSION 3.17.2)
project(Server VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Server 
    src/main.c
    src/api/routes.h
    src/api/routes.c
    src/api/file_controller.h
    src/api/file_controller.c
    src/data/file_repository.h
    src/data/file_repository.c
    src/managers/file_manager.h
    src/managers/file_manager.c
    )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME} ulfius)