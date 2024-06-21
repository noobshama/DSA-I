#include<bits/stdc++.h>
#include"2105045_1_ll_queue.cpp"
using namespace std;
int main()
{   string s;
    cin>> s;
    int len=1;
    while(len)
    {
      Queue<int>A,B,C;
      if(B.length()==C.length())
      {   
        if(B.length()==1)
        {
            B.enqueue(len);
            cout<<"Customer 8 enters queue B"<<endl;
         }
        //  else if(strcmp(s,"A approve"))
        //  {
        //    cout<<"Customer 1 gets the loan"<<endl;
        //  }
        else
        {
        B.enqueue(len);
        cout<<"Customer 1 enters queue B";
        }
     }
    else if(B.length()>C.length())
    {    
        if(B.length()==2)
        {
            C.enqueue(len);
            cout<<"Customer 2 enters queue C"<<endl;

        }
        else
        {
        C.enqueue(len);
        cout<<"Customer 5 enters queue C"<<endl;
        }
    }
    
    // else if(s=="B approve")
    // {
    //    if(B.length()==C.length())
    //    {
    //     B.dequeue();
    //     cout<<"Customer 1 enters queue A"<<endl;
    //    }

    // }
    
    





    cin>>s;
    }
    

}
