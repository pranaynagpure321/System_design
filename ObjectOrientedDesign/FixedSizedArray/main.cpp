#include<iostream>
#include "FixedSizedArray.h"

using namespace std;
int main()
{
    FixedSizedArray<int> vec(10);

    vec[0]=1;
    vec[1]=2;
    vec[3]=3;


    for(auto it = vec.begin() ; it != vec.end(); ++it)
    {
        cout<<*it<<endl;
    }

    cout<<"range based loops--------------\n";
    for(const auto &e : vec)
    {
        cout<<e<<endl;
    }
    cout<<"Hello"<<endl;
}
