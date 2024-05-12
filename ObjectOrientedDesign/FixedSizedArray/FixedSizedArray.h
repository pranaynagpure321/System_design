

template<typename T>

class FixedSizedArray{

    private:

        struct iterator
        {
            using Value = T;
            using Pointer = T*;
            using reference = T&;
            // constructor
            iterator(Pointer ptr) : m_Ptr(ptr){}


            //derefance urinary operator
            reference operator*() const
            {
                return *m_Ptr;
            }

            Pointer operator->()
            {
                return m_Ptr;
            }

            iterator& operator++()  //prefix operator
            {
                m_Ptr++;
                return *this;
            }

            iterator& operator++(T)  //postfix opertor
            {
                iterator temp(*this);
                ++(*this);
                return temp;
            }

            bool operator==(const iterator& other) const
            {
                return this->m_Ptr == other.m_Ptr;
            }

            bool operator!=(const iterator& other)
            {
                return !(*this == other.m_Ptr);
            }

            private:
             Pointer m_Ptr;
        };
    public:

        FixedSizedArray(int cap): m_Capacity(cap) 
        {
            m_Data = new T[m_Capacity];
        }

        T& operator[](int index)
        {
            return m_Data[index];
        }

        size_t capacity()
        {
            return m_Capacity;
        }

        iterator begin()
        {
            return iterator(m_Data);
        }

        iterator end()
        {
            return iterator(&m_Data[m_Capacity]);
        }

    private:
        T* m_Data;
        size_t m_Capacity;

};

/*
invalid initialization of reference of type ‘FixedSizedArray<int>::iterator::reference’ {aka ‘int&’} from expression of type ‘FixedSizedArray<int>::iterator’*/
