
#include <iostream>
#include <string>

using namespace std;

template <class T>

class smart_ptr{

    T * ptr;

    public:
    smart_ptr() : ptr(nullptr)
    {

    }
    smart_ptr(T *ptr)
    {
        this->ptr = ptr;
    } 

    ~smart_ptr() {
        __cleanup__();
    }

    smart_ptr(const  smart_ptr &obj ) = delete;
    smart_ptr& operator=(const smart_ptr &obj) = delete;

    smart_ptr(smart_ptr && dyingObj)
    {
        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }
    smart_ptr& operator=(smart_ptr && dyingObj)
    {

        __cleanup__();
        this->ptr= dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    T* operator->()
    {
        return this->ptr;
    }

    T& operator*()
    {
        return *(this->ptr);
    }

    private: 
    void __cleanup__() {
        if(ptr != nullptr)
        delete ptr;
    }

};

class table
{
    string name;

    public:
    table(string name) : name(name);
    ~table() {}

    void print()
    {
        cout << name << endl;
    }
};

int main()
{
    smart_ptr<table> obj(new table("pranay"));
    obj->print();
    return 0;
}
