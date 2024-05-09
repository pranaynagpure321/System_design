#include<iostream>
#include<vector>
#include<queue>
#include "cus_queue.h"
#include "Vector.h"
//using namespace std;



template<typename T>
void printVector(const Vector<T>& vec)
{
    for(size_t i =0 ; i<vec.size(); i++)
    std::cout<<vec[i]<<std::endl;

    std::cout<<"--------------------------------\n";
}
int main()
{

//    Vector<std::string> vec;

  
//    vec.EmplaceBack("Dilip");
//    vec.EmplaceBack("nagpure");
//    vec.EmplaceBack("tttttttttt");
//    vec.PopFront();
//    //printVector(vec);
   
//    for(Vector<std::string> :: Iterator it = vec.begin() ; it != vec.end(); it++)
//    {
//         std::cout<<*it<<std::endl;
//    }
//    std::cout<<"referacning type"<<std::endl;
//    for(auto &i: vec)
//    std::cout<<i<<std::endl;

     Queue<int> q;

     q.enqueue(1);
     q.enqueue(2);
     q.enqueue(3);
     q.enqueue(4);

   
      std::cout<<q.back()<<std::endl;
     

   return 0;
}
