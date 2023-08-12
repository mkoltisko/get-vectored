
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
        LinearAlgebra/LinearObject.cpp
        LinearAlgebra/LinearObject.hpp
        Robotics/Joint.cpp
        Robotics/Joint.hpp
        Robotics/Robot.cpp
        Robotics/Robot.hpp
        DataStructures/LinkedList.cpp
        DataStructures/LinkedList.hpp
        SmokeTest/TestFixture.hpp
        SmokeTest/TestExecute.hpp
        SmokeTest/VectorTests/VectorTests.cpp
        SmokeTest/VectorTests/VectorTests.hpp
        SmokeTest/MatrixTests/MatrixTests.cpp
        SmokeTest/MatrixTests/MatrixTests.hpp
        SmokeTest/LinkedListTests/LinkedListTests.cpp
        SmokeTest/LinkedListTests/LinkedListTests.hpp)

add_executable(LinearAlgebra ${SOURCES})

target_include_directories(LinearAlgebra PRIVATE ${PROJECT_SOURCE_DIR}/include)

