#ifndef _2105045_2_STACK_H
#define _2105045_2_STACK_H
 
#include<bits/stdc++.h>
//#include"2105045_1_ll_queue.cpp"
#include"2105045_1_a_queue.cpp"
using namespace std;
template<typename L>
class Stack
{
  Queue<L>Stk;
  Queue<L>Stk1;
  public:
  
  void push(L v);
   
  L pop();
  int length();
  L topvalue();
  bool is_Empty();
  void clear();
  void printt();


};
#endif

