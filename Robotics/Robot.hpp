
#ifndef MATRIX_H_ROBOT_HPP
#define MATRIX_H_ROBOT_HPP


#include "Joint.hpp"
#include "../DataStructures/LinkedList.hpp"

enum ROBOT_TYPE
{
    UNDEFINED = 0,
    ONE_AXIS = 1,
    PLANAR = 2,
    CARTESIAN = 3,
    SCARA = 4,
    FIVE_AXIS = 5,
    SIX_AXES = 6,
    SEVEN_AXES = 7
};

class Robot : LinkedList<Joint>
{
public:

    Robot() {}
    ~Robot() {}

    Robot(const Robot& obj) {}
    Robot& operator= (const Robot& obj) {}

    LinearObject forwardKinematics(LinearObject& inputAngles);

    LinearObject inverseKinematics(LinearObject& endpointFrame);

    LinearObject forwardDynamics();

    LinearObject inverseDynamics();
private:

};


#endif //MATRIX_H_ROBOT_HPP
