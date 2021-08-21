cmake_minimum_required(VERSION 3.0.0)
project(Client VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Client 
    src/main.c
    src/services/service.h
    src/services/service.c
    src/services/info_service.h
    src/services/info_service.c
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(OUTPUT_NAME index)
include(CPack)

target_link_libraries(${PROJECT_NAME} curl)