#pragma once


template<typename Vector>
class VectorIterator
{

    public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;
    public: 
    VectorIterator(PointerType ptr) : m_Ptr(ptr){}

    VectorIterator& operator++()//prefixiterator
    {
        m_Ptr++;
        return *this;
    }

    VectorIterator& operator++(int) ///postfix iterator
    {
        VectorIterator it = *this;
        ++(*this);
        return it;
    }


    VectorIterator& operator--()//prefixiterator
    {
        m_Ptr--;
        return *this;
    }

    VectorIterator& operator--(int) ///postfix iterator
    {
        VectorIterator it = *this;
        --(*this);
        return it;
    }

    ReferenceType operator[](int index)
    {
        return *(m_Ptr+index);
    }
    PointerType operator->()
    {
        return m_Ptr;
    }
    ReferenceType operator*()
    {
        return *m_Ptr;
    }

    bool operator==(const VectorIterator& other) const
    {
        return m_Ptr == other.m_Ptr;
    }
    bool operator!=(const VectorIterator& other) const
    {
        return !(*this == other);
    }
    private:

    PointerType m_Ptr;

};

template <typename T>                             // template to use generic types in Vector

class Vector
{
    public:
    using ValueType = T;
    using Iterator = VectorIterator<Vector<T>>;    // instead of calling class everywhere we are assigning alias here

    private:
        T* m_Data = nullptr;               // pointer to array of data
        size_t m_Size = 0;                 // size of vector
        size_t m_Capacity =0;               // capacity to keep track
    public:
        Vector(/* args */)
        {
            ReAlloc(2);
        }

        ~Vector()
        {
            //if u use ptr in T then its your responsibility to delete those pointers
            delete[] m_Data;
        }

        void PushBack(const T&& value)
        {
            if(m_Size >= m_Capacity)
            ReAlloc(2*m_Capacity );

            m_Data[m_Size] = std::move(value);
            m_Size++;
        }

        void PopFront()
        {
            if(m_Size > 0)
            {
                for(size_t i =0 ; i< m_Size-1; i++)
                m_Data[i] = std::move(m_Data[i+1]);
                //m_Data[0].~T();

                m_Size--;
                //++m_Data;
            }
        }
        void PopBack()
        {
            if(m_Size > 0)
            {
                m_Size--;
                m_Data[m_Size].~T();
            }
        }

        void Clear()
        {
            for(size_t i =0 ;i < m_Size; i++)
            m_Data[i].~T();

            m_Size=0;
        }

        template<typename... Args>
        T& EmplaceBack(Args&&... args)
        {
            if(m_Size >= m_Capacity)
            ReAlloc(2*m_Capacity );


            m_Data[m_Size] = T(std::forward<Args>(args)...); // forward used to unpacke arguments

            return m_Data[m_Size++];
        }

        int size() const
        {
            return m_Size;
        }

        const T& operator[](size_t index) const
        {
            if(index >= m_Size)
            {
                //throw std:: error("out of bounds");
            }
            return m_Data[index];
        }

        Iterator begin()   // begin iterator
        {
            return Iterator(m_Data);
        }
        Iterator end()      // after last element iterator
        {
            return Iterator(m_Data + m_Size);
        }
        T& front()       // referance to first element in list
        {
            return *m_Data;
        }
        T& back()       // referance to last element in list
        {
            return *(m_Data+m_Size-1);
        }
    private:
        void ReAlloc(size_t newCapacity)        // is capacity is full then this fuction creates new block of memory double the size and copy all element from old one to new one
        {
            T *newBlock = new T[newCapacity];

            if(newCapacity < m_Size)
            m_Size = newCapacity;

            for(size_t i =0 ;i < m_Size ;i++)
            newBlock[i] = std::move(m_Data[i]);

            delete[] m_Data;
            m_Data = newBlock;
            m_Capacity = newCapacity;
        }
};

 
