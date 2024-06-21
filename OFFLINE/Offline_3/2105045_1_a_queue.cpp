#include<bits/stdc++.h>
#include"2105045_1_a_queue.h"
using namespace std;

template <typename A>
Queue<A>::Queue()
{
    maxsize=5;
    ar1=new A[maxsize];
    front=1;
    rear=0;
     Arr=new Array<A>;
   Arr->init(maxsize,0,{});
    
    len=0;
}
template <typename A>
void Queue<A>::enqueue(A v)
{    
    if((rear+2)%maxsize==front)
    {    
        obj=new Array<A>;
         maxsize*=2;
        obj->init(maxsize,0,{});
        obj->moveToPos(front);
        Arr->moveToPos(front);
         while(Arr->currPos()!=((rear+1)%maxsize))
        {   
             A it=Arr->getvalue();
            obj->insert(it);
            obj->next();
            Arr->moveToPos((Arr->currPos()+1)%maxsize);
            
        }
        delete Arr;
        Arr=obj;
         front = 1;
        rear = Arr->length();
  }
     rear=(rear+1)%maxsize;
    Arr->moveToPos(rear);
    Arr->insert(v);
    len++;
}
template <typename A>
A Queue<A>::dequeue()
{    
    Arr->moveToPos(front);
    A it=Arr->getvalue();
    front=(front+1)%maxsize;
    len--;
    return it;
}
template <typename A>   
int Queue<A>::length()
{
    return ((rear+maxsize)-front+1)%maxsize;
}
template <typename A>
A Queue<A>::Rear()
{
    Arr->moveToPos(rear);
    return Arr->getvalue();
    
}
template <typename A>
A Queue<A>::Front()
{   
    Arr->moveToPos(front);
    return Arr->getvalue();
}
template <typename A>
bool Queue<A>::is_Empty()
{
    if (length()==0)
    {
        return 1;
    }
    return 0;
}
template <typename A>
void Queue<A>::clear()
{
    front=1;
    rear=0;
     delete Arr;
    Arr=new Array<A>;
    Arr->init(maxsize,5,ar1);
}
template <typename A>
void Queue<A>::print()
{    
        
        if(length()==0)
        {
        cout<<"<>"<<endl;
        }
    
    else
    {  
        cout<<"<"<<" ";
    Arr->moveToPos(front);
    for(int i=0;i<length();i++)
    {   
        cout<<Arr->getvalue()<<" ";
        Arr->next();
    }
    cout<<">"<<endl;
    }
}
