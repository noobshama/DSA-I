#include<bits/stdc++.h>
#include"2105045_2_stack.h"
using namespace std;
template<typename L>
void Stack<L>::push(L v)
  {
    Stk.enqueue(v);
  }
   template<typename L>
  L Stack<L>:: pop()
  {
    for(int i=1;i<=length();i++)
    {
      if(i<length())
      {
        L x=Stk.dequeue();
        Stk.enqueue(x);
      }
      else if(i==length())
      {
         L x=Stk.dequeue();
         //break;
         return x;
         //break;

      }
    }

  }
  template<typename L>
  int Stack<L>:: length()
  {
    Stk.length();
  }
  template<typename L>
  L Stack<L>::topvalue()
  {
    Stk.Rear();
  }
  template<typename L>
  bool Stack<L>:: is_Empty()
  {
    Stk.is_Empty();
  }
  template<typename L>
  void Stack<L>:: clear()
  {
    Stk.clear();
  }
template<typename L>
  void Stack<L>:: printt()
  {
    Stk.print();
  }




