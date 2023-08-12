
#include "LinkedList.hpp"
#include <string>

template<typename T>
LinkedList<T>::LinkedList(T* start)
{
    if(start == nullptr)
    {
        m_pHead = nullptr;
        m_Size = 0;
    }
    else
    {
        m_pHead = new Node(*start, nullptr);
        m_Size = 1;
    }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    m_pHead = other.m_pHead;
    m_Size = other.m_Size;
}

template<typename T>
LinkedList<T>::~LinkedList<T>()
{
    Node* pCurrent = m_pHead;
    Node* pNext;
    while(pCurrent != nullptr)
    {
        pNext = pCurrent->m_pNext;
        delete pCurrent;
        pCurrent = pNext;
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if(this == &other)
    {
        return *this;
    }
    delete this;
    m_pHead = other.m_pHead;
    m_Size = other.m_Size;
}

template<typename T>
T LinkedList<T>::get(unsigned int index)
{
    unsigned int count = 0;
    Node* pCurrent = m_pHead;
    while(pCurrent != nullptr)
    {
        if(count == index)
        {
            return pCurrent->m_Element;
        }
        ++count;
        pCurrent = pCurrent->m_pNext;
    }
    return NULL;
}

template<typename T>
void LinkedList<T>::push(T& newHeadElement)
{
    ++m_Size;
    m_pHead = new Node(newHeadElement, m_pHead);
}

template<typename T>
void LinkedList<T>::push_back(T& newTailElement)
{
    ++m_Size;
    Node* pCurrent = m_pHead;
    if(pCurrent == nullptr) // empty list
    {
        m_pHead = new Node(newTailElement, nullptr);
        return;
    }
    // Iterate until at list's end
    while(pCurrent->m_pNext != nullptr)
    {
        pCurrent = pCurrent->m_pNext;
    } 
    pCurrent->m_pNext = new Node(newTailElement, nullptr);
}

template<typename T>
T LinkedList<T>::pop()
{
    if(m_pHead == nullptr)
    {
        return NULL;
    }
    --m_Size;
    T oldElement = m_pHead->m_Element;  // copy out old data to be returned last
    Node* pOldHead = m_pHead;           // get reference to old head for deletion
    m_pHead = m_pHead->m_pNext;         // update member head pointer
    delete pOldHead;                    // de-allocate previous head memory
    return oldElement;                  // return copied data
}

template<typename T>
T LinkedList<T>::pop_back()
{
    Node* pCurrent = m_pHead;
    while(pCurrent != nullptr)
    {
        if(pCurrent->m_pNext == nullptr)
        {
            T toReturn = pCurrent->m_Element;
            delete pCurrent;
            --m_Size;
            return toReturn;
        }
        pCurrent = pCurrent->m_pNext;
    }
    return NULL;
}

// Index to insert at should be zero-indexed, i.e. insert at head is index 0
template<typename T>
void LinkedList<T>::insert(unsigned int index, T& newElement)
{
    // Easy case if inserting at head
    if(index == 0)
    {
        m_pHead = new Node(newElement, m_pHead);
        ++m_Size;
        return;
    }
    
    // Iterate into list and insert between nodes
    unsigned int count = 1; // already took care of head
    Node* pPrevious = m_pHead;
    Node* pCurrent = m_pHead->m_pNext;
    while(pCurrent != nullptr)
    {
        if(count == index)
        {
            pCurrent = new Node(newElement, pCurrent);
            pPrevious->m_pNext = pCurrent;
            ++m_Size;
            return;
        }
        ++count;
        pPrevious = pCurrent;
        pCurrent = pCurrent->m_pNext;
    }
    // If trying to insert past the list then nothing happens
    return;
}

template<typename T>
void LinkedList<T>::remove(unsigned int index)
{
    unsigned int count = 0;
    Node* pPrevious = nullptr;
    Node* pCurrent = m_pHead;
    while(pCurrent != nullptr)
    {
        if(count == index)
        {
            if(pPrevious != nullptr)
            {
                pPrevious->m_pNext = pCurrent->m_pNext;
            }
            delete pCurrent;
            --m_Size;
            return;
        }
        ++count;
        pPrevious = pCurrent;
        pCurrent = pCurrent->m_pNext;
    }
    // If trying to remove past the list then nothing happens
    return;
}

template<typename T>
std::string LinkedList<T>::to_string()
{
    if(m_pHead == nullptr)
    {
        return nullptr;
    }

    try
    {
        std::stringstream resultStream;    
        Node* pCurrent = m_pHead;
        while(pCurrent != nullptr)
        {
            resultStream << pCurrent->m_Element;
            pCurrent = pCurrent->m_pNext;
            if(pCurrent != nullptr)
            {
                resultStream << ", ";
            }
        }
        resultStream << std::endl;
        return resultStream.str();
    }
    catch(const std::exception& e)
    {
        // std::out << e.what() << '\n';
    }
    return nullptr;
}

template class LinkedList<float>;