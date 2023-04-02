
#include "LinkedList.h"


template<typename T>
LinkedList<T>::LinkedList(T& start)
{
    m_pHead = Node(start, nullptr);
    m_pTail = m_pHead;
    if(start != nullptr)
    {
        m_Size = 1;
    }
    else
    {
        m_Size = 0;
    }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{

}

template<typename T>
LinkedList<T>::~LinkedList<T>()
{

}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{

}

template<typename T>
T& LinkedList<T>::get(unsigned int index)
{
    unsigned int count = 0;
    Node* pCurrent = m_pHead;
    while(pCurrent != nullptr)
    {
        if(count == index)
        {
            return pCurrent->m_pElement;
        }

        ++count;
        pCurrent = pCurrent->m_pNext;
    }
    return nullptr;
}

template<typename T>
void LinkedList<T>::push(T& newHeadElement)
{
    m_pHead = new Node(newHeadElement, m_pHead);
}

template<typename T>
void LinkedList<T>::push_back(T& newTailElement)
{
    m_pTail->m_pNext = new Node(newTailElement, nullptr);
    m_pTail = m_pTail->m_pNext;
}

template<typename T>
T LinkedList<T>::pop()
{
    T oldElement = m_pHead->m_pElement; // copy out old data to be returned last
    Node& rOldHead = *m_pHead;          // get reference to old head for deletion
    m_pHead = m_pHead->m_pNext;         // update member head pointer
    delete rOldHead;                    // de-allocate previous head memory
    return oldElement;                  // return copied data
}

template<typename T>
T LinkedList<T>::pop_back()
{
    Node* pCurrent = m_pHead;
    while(pCurrent != nullptr)
    {
        if(pCurrent->m_pNext->m_pElement == m_pTail->m_pElement)
        {
            T oldElement = m_pTail->m_pElement; // copy out old data to be returned last
            Node& rOldTail = *m_pTail;          // get reference to old tail for deletion
            m_pTail = pCurrent;                 // update member tail pointer
            delete rOldTail;                    // de-allocate previous tail memory
            m_pTail->m_pNext = nullptr;         // update member tail's next which should no longer exist
            return oldElement;                  // return copied data
        }
        pCurrent = pCurrent->m_pNext;
    }
    return nullptr;
}

template<typename T>
void LinkedList<T>::insert(unsigned int index, T& newElement)
{
    unsigned int count = 0;
    Node* pPrevious = nullptr;
    Node* pCurrent = m_pHead;
    while(pCurrent != nullptr)
    {
        if(count == index)
        {
            pCurrent = new Node(newElement, pCurrent);
            pPrevious->m_pNext = pCurrent;
            return;
        }

        ++count;
        pPrevious = pCurrent;
        pCurrent = pCurrent->m_pNext;
    }
    // if trying to insert past the list then nothing happens
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
            Node& rOldNode = *pCurrent;
            pPrevious->m_pNext = pCurrent->m_pNext;
            delete rOldNode;
            return;
        }

        ++count;
        pPrevious = pCurrent;
        pCurrent = pCurrent->m_pNext;
    }
    // if trying to remove past the list then nothing happens
    return;
}

