
#ifndef MATRIX_H_ROBOT_HPP
#define MATRIX_H_ROBOT_HPP


#include "Joint.hpp"


class Robot
{
public:

    Robot();

    ~Robot();

    Robot(const Robot& obj);
    Robot& operator= (const Robot& obj);

    void addJoint(Joint& obj);

    void removeJoint(unsigned int index);

    Joint& getJoint(unsigned int index);

    LinearObject forwardKin(LinearObject& inputAngles);

    LinearObject inverseKin(LinearObject& endpointFrame);

private:


    struct JOINT_NODE
    {
        Joint* m_pElement;
        Robot::JOINT_NODE* m_pNext;
        Robot::JOINT_NODE* m_pPrev;
    };

    unsigned int m_numJoints;

    JOINT_NODE* m_pBaseJoint;
    JOINT_NODE* m_pEndJoint;

};


#endif //MATRIX_H_ROBOT_HPP
