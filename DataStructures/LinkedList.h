
#ifndef MATRIX_H_LINKEDLIST_H
#define MATRIX_H_LINKEDLIST_H

template <typename T>
class LinkedList
{
public:

    LinkedList<T>(T& start = nullptr);

    LinkedList<T>(const LinkedList<T>& other);

    ~LinkedList<T>();

    LinkedList& operator= (const LinkedList<T>& other);

    T& get(unsigned int index);

    void push(T& newHead);

    void push_back(T& newTail);

    T pop();

    T pop_back();

    void insert(unsigned int index, T& newElement);

    void remove(unsigned int index);

private:

    struct Node
    {
        T* m_pElement;
        Node* m_pNext;
    };

    Node* m_pHead;
    Node* m_pTail;
    unsigned int m_Size;
};


#endif //MATRIX_H_LINKEDLIST_H
