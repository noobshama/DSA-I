#ifndef _2105045_1_LL_QUEUE_H_
#define _2105045_1_LL_QUEUE_H_


#include<bits/stdc++.h>
#include"LIST.cpp"
using namespace std;

template <typename A>
class Queue
{
LINK <A> *Que;
//LINK<L>*QU;
public:
  Queue();
void enqueue (A v);
A dequeue();
int length();
A Front();
A Rear();
bool is_Empty();
void clear();
void print();
    

};
#endif
