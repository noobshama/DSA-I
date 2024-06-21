#ifndef _2105045_1_A_QUEUE_H_
#define _2105045_1_A_QUEUE_H_

#include<bits/stdc++.h>
#include"Arr.cpp"
using namespace std;

template <typename A>
class Queue
{   
    Array<A>*Arr;
    Array<A>*obj;
    //Array<A>*obj;
            //obj=new Array<A>;
    int maxsize;
    int front;
    int rear;
    A *ar1;
    int len;
    public:
    Queue();
    void enqueue(A v);
    A dequeue();
      
    int length();
    A Rear();
      A Front();
    bool is_Empty();
    void clear();
    
    void print();
    

};

#endif