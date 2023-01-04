cmake_minimum_required(VERSION 3.17)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinearAlgebra
        main.cpp
        Vector.cpp
        Vector.h
        Properties.cpp
        Properties.h
        Operations.cpp
        Operations.h
        Matrix.cpp
        Matrix.h)

#set(SOURCE
##        ${SOURCE}
#        ${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp
#        ${CMAKE_CURRENT_SOURCE_DIR}/Operations.cpp
#        ${CMAKE_CURRENT_SOURCE_DIR}/Properties.cpp
#        PARENT_SCOPE
#        )
#set(HEADERS
##        ${HEADERS}
#        ${CMAKE_CURRENT_SOURCE_DIR}/Operations.h
#        ${CMAKE_CURRENT_SOURCE_DIR}/Properties.h
#        ${CMAKE_CURRENT_SOURCE_DIR}/Vector.h
#        ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.h
#        PARENT_SCOPE
#        )