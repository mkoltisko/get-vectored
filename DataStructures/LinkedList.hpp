
#ifndef MATRIX_H_LINKEDLIST_HPP
#define MATRIX_H_LINKEDLIST_HPP

#include <string>
#include <sstream>

template <typename T> 
class LinkedList
{
public:

    LinkedList<T>(T* start = nullptr);
    ~LinkedList<T>();

    LinkedList<T>(const LinkedList<T>& other);              // copy constructor
    LinkedList& operator= (const LinkedList<T>& other);     // assignment operator

    T get(unsigned int index);

    void push(T& newHead);

    void push_back(T& newTail);

    T pop();

    T pop_back();

    void insert(unsigned int index, T& newElement);

    void remove(unsigned int index);

    std::string to_string();

    inline unsigned int length() { return m_Size; }

private:

    struct Node
    {
        T m_Element;
        Node* m_pNext;

        Node(T element, Node* next = nullptr) :
            m_Element(element),
            m_pNext(next)
            {}
    };

    Node* m_pHead;
    unsigned int m_Size;
};

#endif //LINKEDLIST_HPP
