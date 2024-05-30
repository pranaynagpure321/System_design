

/*
 priority queue using vector or array

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class PriorityQueue
{
    int size =0;
    //vector<int> pq = vector<int>(10000,0);
    int pq[100];
   
    public:

    PriorityQueue() { this->size =0; pq[0] = -1;}

    int getsize() { return this->size;}
    int top() { return pq[1];}
    void insert(int value)
    {
       size = size +1;

       int index = size;
       pq[index] = value;

       while (index > 1)
       {
            int parent = index / 2;
            if (pq[parent] < pq[index])
            {
                swap(pq[index], pq[parent]);
                index = parent;
            }
            else return;
       }
       
        
    }

    void pop()
    {
        if(size <= 0) return;
        pq[1] = pq[size];       // assigne first element to last then heapefy
        size--;

        int i = 1;
        while( i < size)
        {
            int left = pq[i*2];  
            int right = pq[i*2+1];

            int larger = left > right ? 2*i : 2*i+1;  //check left or right child is largerr then swap that
            if(pq[i] < pq[larger])
            {
                swap(pq[i],pq[larger]);
                i = larger;
            }
            else return;
        }
    }


    void print()
    {
        for(int i = 1; i <= size; i++)
        {
            cout << pq[i] << " ";
        }
        cout<<endl;
    }

};

class pranay 
{
    int arr[100];
    int size =0;

    public:

    pranay() : size(0) { arr[0] = -1;}

    int getsize() { return size;}
    int top() { return arr[1];}

    void insert(int val)
    {
        size++;

        int index = size;
        arr[size] = val;

        while(index > 1)
        {
            int parent = index/2;
            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        } 
    }


    void pop()
    {
        arr[1] = arr[size];
        int index = 1;
        size--;

        while( index < size)
        {
            int left = index * 2;
            int right = index * 2 + 1;

            int larger = arr[left] > arr[right] ? left : right; 

            if(arr[larger] > arr[index])
            {
                swap(arr[larger], arr[index]);
                index = larger;
            }
            else return;
        }
    }
};

int main()
{
    pranay  *pq = new pranay();

    pq->insert(10);
    pq->insert(20);
    pq->insert(30);
    pq->insert(4);

   // pq->print();

    while(pq->getsize() > 0)
    {
        cout<<" "<<pq->top()<<endl;
        pq->pop();
    }
    
}
