#include<bits/stdc++.h>

using namespace std;
template <typename S> 
class Stack
{ 
    S *arr;
    int top,maxsize;
    public:
    Stack(int size1)
    { 
        maxsize=size1;
        top=0;
        arr=new S[maxsize];
    }
    Stack()
    {
        maxsize=20;
        top=0;
        arr=new S[maxsize];
    }
    /*~Stack()
    {
        delete [] arr;
    }*/
    
    void clear()
    {
        if(arr)
        {
            delete []arr;
        }
        top=0;
    }
    void push(S V)
    {
        if(top==maxsize)
        {
            S *a=new S[maxsize];
            for(int i=0;i<top;i++)
            {
                a[i]=arr[i];
            }
            maxsize=maxsize*2;
            arr=new S[maxsize];
            for(int i=0;i<top;i++)
            {
                arr[i]=a[i];
            }
            delete []a;
        }
        arr[top++]=V;
    }
    S pop()
    {
        if(top==0)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        S ans=arr[--top];
        return ans;
    }
    int length()
    {
       return top;
    }
    S topvalue()
    {
        if(top==0)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top-1];
    }
    bool isEmpty()
    {    bool res=true;
        if(top==0)
        {
            
            return res;
        }
        else
        {
            return !res;
        }
    }
    void print ()
    {
        if(top==0)
        {
            cout<<"<>"<<endl;
        }
        else
        {
            cout<<"<";
            for(int i=0;i<top;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<">"<<endl;
        }
    }

};