
cmake_minimum_required(VERSION 3.17)

project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 17)

#        Vector.cpp
#        include/Vector.hpp
#        Properties.cpp
#        include/Properties.hpp
#        Operations.cpp
#        include/Operations.hpp
#        Matrix.cpp
#        include/Matrix.hpp)

add_executable(LinearAlgebra main.cpp)

target_include_directories(LinearAlgebra PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(LinearAlgebra PUBLIC ${PROJECT_SOURCE_DIR}/source)



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