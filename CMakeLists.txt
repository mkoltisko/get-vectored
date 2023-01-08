
cmake_minimum_required(VERSION 3.17)

project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 17)

set( SOURCES
        main.cpp
        source/Vector.cpp
        include/Vector.hpp
        source/Properties.cpp
        include/Properties.hpp
        source/Operations.cpp
        include/Operations.hpp
        source/Matrix.cpp
        include/Matrix.hpp
        SmokeTest/TestFixture.hpp
        SmokeTest/TestExecute.hpp
        SmokeTest/VectorTests/VectorTests.cpp
        SmokeTest/VectorTests/VectorTests.hpp
        HelpfulFunctions.hpp)

add_executable(LinearAlgebra ${SOURCES} HelpfulFunctions.hpp)

target_include_directories(LinearAlgebra PRIVATE ${PROJECT_SOURCE_DIR}/include)
#target_include_directories(LinearAlgebra PUBLIC ${PROJECT_SOURCE_DIR}/source)

