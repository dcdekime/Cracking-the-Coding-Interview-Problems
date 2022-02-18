#ifndef CUSTOM_ARRAY_H
#define CUSTOM_ARRAY_H

#include <stddef.h>

template<typename T>
class CVector
{
public:
    CVector();
    void PushBack(const T& value);
    size_t Size() const;
    
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    
private:
    // private member functions
    void ReAlloc(size_t newCapacity);
    
private:
    // private member variables
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};
#endif
    

