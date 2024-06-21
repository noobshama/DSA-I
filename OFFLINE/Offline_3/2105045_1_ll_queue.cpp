#include<bits/stdc++.h>
#include"2105045_1_ll_queue.h"
using namespace std;
template <typename A>
Queue<A>::Queue()
  {  
    Que=new LINK<A>;
    Que->init(0);
    
  }
  template <typename A>
  void Queue<A>::enqueue (A v)
{  
   Que->movetoEnd();
   Que->next();
   Que->insert(v);
}
template <typename A>
A Queue<A>::dequeue()
{
    Que->movetoStart();
    Que->remove();
}
template <typename A>
int Queue<A>::length()
{
    return Que->length();
}
template <typename A>
A Queue<A>::Front()
{
    Que->movetoStart();
    A ans;
    ans=Que->getvalue();
    return ans;
}
template <typename A>
A Queue<A>::Rear()
{
    Que->movetoEnd();
    A ans;
    ans=Que->getvalue();
    return ans;

}
template <typename A>
bool Queue<A>:: is_Empty()
    {    
        bool res=true;
        if(Que->length()==0)
        {
            
            return res;
        }
        else
        {
            return !res;
        }
    }
    template <typename A>
    void Queue<A>:: clear()
    {
        //   delete Que;
        //   Que=new LINK<L>;
        //   Que->init(0);
        for(Que->movetoStart();Que->currPos()<Que->length();)
    {
          Que->remove();
          
    }
    } 
    
    template <typename A>
    void Queue<A>:: print()
    {
        // Que.print1();
        if(length()==0)
        {
            cout<<"<>"<<endl;
        }
        else
        {
        cout<<"<"<<" ";
        Que->movetoStart();
        for(int i=0;i<Que->length();i++)
        {
            cout<<Que->getvalue()<<" ";
            Que->next();
        }
        cout<<">"<<endl;
        }
    }
    



