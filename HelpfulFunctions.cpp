
#include "HelpfulFunctions.hpp"

void print(const std::string &message)
{
    std::cout << message << std::endl;
}

void print(const Vector* v)
{
    assert(v != nullptr);
    print(v->to_string());
}

void AssertMessage(bool condition, const std::string& message)
{
    if (!condition)
    {
        print(message);
        assert(condition);
    }
}
