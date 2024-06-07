cmake_minimum_required(VERSION 3.27)
project(TimPark++)

set(CMAKE_CXX_STANDARD 23)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
# ${CMAKE_BINARY_DIR} instead of bin


add_executable(
        TimPark++ src/main.cpp
        src/menus.cpp
#        src/handlers.cpp
        include/menus.h
#        include/handlers.h
        include/main.h
        src/utils.cpp
        include/utils.h
#        src/admin_auth.cpp
#        include/admin_auth.h
        src/Administrator.cpp
        include/Administrator.h
        src/ParkingLot.cpp
        include/ParkingLot.h
        src/inputs.cpp
        src/print.cpp
        include/print.h
)