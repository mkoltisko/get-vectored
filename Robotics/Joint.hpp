
#ifndef MATRIX_H_JOINT_HPP
#define MATRIX_H_JOINT_HPP


#include "../LinearAlgebra/LinearObject.hpp"

enum JOINT_TYPE
{
    REVOLUTE = 0,
    PRISMATIC = 1,
};

class Joint
{
public:

    explicit Joint(JOINT_TYPE type = REVOLUTE);
    Joint(JOINT_TYPE type, float first, float second, float third);

    ~Joint();

    Joint(const Joint& obj);
    Joint& operator= (const Joint& obj);

    void setParameters(float first, float second, float third);

    LinearObject& evaluateTransform(float input);

    inline float getA() const { return m_a; }
    inline float getD() const { return m_d; }
    inline float getAlpha() const {return m_alpha; }
    inline float getTheta() const { return m_theta; }

private:

    JOINT_TYPE m_Type;

    float m_a;
    float m_d;
    float m_alpha;
    float m_theta;

    LinearObject* m_pTransform;
    LinearObject* m_pRotation;
    LinearObject* m_pTranslation;

};


#endif //MATRIX_H_JOINT_HPP
