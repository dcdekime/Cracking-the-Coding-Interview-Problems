#include "Custom_Array.h"

template<typename T>
CVector<T>::CVector()
{
    // initialize with size of 2
    ReAlloc(2);
}

template<typename T>
void CVector<T>::PushBack(const T& value)
{
    if (m_Size >= m_Capacity)
    {
        ReAlloc(m_Capacity + (m_Capacity/2));
    }
    
    m_Data[m_Size] = value;
    m_Size++;
}

template<typename T>
size_t CVector<T>::Size() const
{
    return m_Size;
}

template<typename T>
const T& CVector<T>::operator[](size_t index) const
{
    if (index >= m_Size)
    {
        // assert
    }
    return m_Data[index];
}

template<typename T>
T& CVector<T>::operator[](size_t index)
{
    if (index >= m_Size)
    {
        // assert
    }
    return m_Data[index];
}

template<typename T>
void CVector<T>::ReAlloc(size_t newCapacity)
{
    // 1. allocate a new block of memory
    T* newBlock = new T[newCapacity];
    
    if (newCapacity < m_Size)
        m_Size = newCapacity;
    
    // 2. copy/move old elements into new block
    for (size_t i=0; i < m_Size; i++)
        newBlock[i] = m_Data[i];
    
    // 3. delete
    delete[] m_Data;
    m_Data = newBlock;
    m_Capacity = newCapacity;
}



