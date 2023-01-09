
#include "HelpfulFunctions.hpp"

void print(const std::string &message)
{
    std::cout << message << std::endl;
}

void print(const LinearObject* matrix)
{
    assert(matrix != nullptr);
    print(matrix->to_string());
}

void assertMessage(bool condition, const std::string& message)
{
    if (condition)
    {
        // true so nothing else required
        return;
    }
    if(!message.empty())
    {
        print(message);
    }
    assert(condition);
}
