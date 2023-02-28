
cmake_minimum_required(VERSION 3.17)

project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 17)

set( SOURCES
        main.cpp
        HelpfulFunctions.cpp
        HelpfulFunctions.hpp
        LinearAlgebra/Properties.cpp
        LinearAlgebra/Properties.hpp
        LinearAlgebra/Operations.cpp
        LinearAlgebra/Operations.hpp
        SmokeTest/TestFixture.hpp
        SmokeTest/TestExecute.hpp
        SmokeTest/VectorTests/VectorTests.cpp
        SmokeTest/VectorTests/VectorTests.hpp
        SmokeTest/MatrixTests/MatrixTests.cpp
        SmokeTest/MatrixTests/MatrixTests.hpp
        LinearAlgebra/LinearObject.cpp
        LinearAlgebra/LinearObject.hpp
        Robotics/Joint.cpp Robotics/Joint.hpp Robotics/Robot.cpp Robotics/Robot.hpp)

add_executable(LinearAlgebra ${SOURCES})

target_include_directories(LinearAlgebra PRIVATE ${PROJECT_SOURCE_DIR}/include)
#target_include_directories(LinearAlgebra PUBLIC ${PROJECT_SOURCE_DIR}/source)

