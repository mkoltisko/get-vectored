
#include "Joint.hpp"

Joint::Joint(JOINT_TYPE type) :
    m_Type(type),
    m_a(0),
    m_d(0),
    m_alpha(0),
    m_theta(0)
{
    m_pTransform = new LinearObject(4, 4);
    m_pRotation = new LinearObject(3, 3);
    m_pTranslation = new LinearObject(3, 1);
}

Joint::Joint(JOINT_TYPE type, float first, float second, float third) :
    m_Type(type),
    m_a(0),
    m_d(0),
    m_alpha(0),
    m_theta(0)
{
    setParameters(first, second, third);

    m_pTransform = new LinearObject(4, 4);
    m_pRotation = new LinearObject(3, 3);
    m_pTranslation = new LinearObject(3, 1);
}

Joint::Joint(const Joint& obj) :
    m_Type(obj.m_Type),
    m_a(obj.m_a),
    m_d(obj.m_d),
    m_alpha(obj.m_alpha),
    m_theta(obj.m_theta)
{
    m_pTransform = new LinearObject(4, 4);
    m_pRotation = new LinearObject(3, 3);
    m_pTranslation = new LinearObject(3, 1);

    (*m_pTransform) = (*obj.m_pTransform);
    (*m_pRotation) = (*obj.m_pRotation);
    (*m_pTranslation) = (*obj.m_pTranslation);
}

Joint& Joint::operator=(const Joint &obj)
{
    if(this == &obj)
    {
        return *this;
    }

    m_Type = obj.m_Type;
    m_a = obj.m_a;
    m_d = obj.m_d;
    m_alpha = obj.m_alpha;
    m_theta = obj.m_theta;

    delete m_pTransform;
    delete m_pRotation;
    delete m_pTranslation;

    m_pTransform = new LinearObject(4, 4);
    m_pRotation = new LinearObject(3, 3);
    m_pTranslation = new LinearObject(3, 1);

    (*m_pTransform) = (*obj.m_pTransform);
    (*m_pRotation) = (*obj.m_pRotation);
    (*m_pTranslation) = (*obj.m_pTranslation);

    return *this;
}

Joint::~Joint()
{
    delete m_pTransform;
    delete m_pRotation;
    delete m_pTranslation;

    m_pTransform = nullptr;
    m_pRotation = nullptr;
    m_pTranslation = nullptr;
}

void Joint::setParameters(float first, float second, float third)
{
    if(m_Type == REVOLUTE)
    {
        m_a = first;
        m_d = second;
        m_alpha = third;
    }
    else if(m_Type == PRISMATIC)
    {
        m_a = first;
        m_alpha = second;
        m_theta = third;
    }
}

LinearObject& Joint::evaluateTransform(float angle)
{

    return *m_pTransform;
}
