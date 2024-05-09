//custome queue class with underlaying custome vector class
#include "Vector.h"
template<typename T>
class Queue{

    public:
    Queue() : m_size(0) {} 
    //using Queue<T> :: Iterator = VectorIterator<Vector<T>>;

    void enqueue(T data)
    {
        que.EmplaceBack(data);
        m_size++;
    }

    void dequeue()
    {
        que.PopFront();
        m_size--;
    }

    T& front()
    {
      return que.front();
    }

    T& back()
    {
      return que.back();
    }


    int size()
    {
      return m_size;
    }

    private:
    Vector<T> que;
    size_t m_size =0;

};
