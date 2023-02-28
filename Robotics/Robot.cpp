
#include "Robot.hpp"

Robot::Robot() :
        m_numJoints(0),
        m_pBaseJoint(nullptr),
        m_pEndJoint(nullptr)
{}

Robot::~Robot()
{
    m_pBaseJoint;
}

Robot::Robot(const Robot& obj)
{

}

Robot& Robot::operator=(const Robot &obj)
{
    return *this;
}

void Robot::addJoint(Joint& obj)
{
    JOINT_NODE* newNode = new JOINT_NODE();
    newNode->m_pElement = &obj;
    newNode->m_pNext = nullptr;
    newNode->m_pPrev = m_pEndJoint;

    m_pEndJoint->m_pNext = newNode;

    m_pEndJoint = newNode;
}

void Robot::removeJoint(unsigned int index)
{

}

Joint& Robot::getJoint(unsigned int index)
{
    assertMessage(index < m_numJoints, "Joint index out of bounds");
    JOINT_NODE* current = m_pBaseJoint;
    for(int i = 0; i < index && current->m_pNext != nullptr; ++i)
    {
        current = current->m_pNext;

    }
    return *current->m_pElement;
}

LinearObject Robot::forwardKin(LinearObject &inputAngles)
{
    return LinearObject();
}

LinearObject Robot::inverseKin(LinearObject &endpointFrame)
{
    return LinearObject();
}
