#include<bits/stdc++.h>
using namespace std;
template <typename A>
class Array{


    int maxSize;
    int listSize;
    int sizeIncrease;
    int curr;
    A *arr;
    public:

  void init (int size1,int size2,A *ar)
 {  
    arr=new A[size1];
    maxSize=size1;
    sizeIncrease = size1;
    listSize=size2;
    curr=0;
    
    for(int i=0; i<listSize; i++)
    {
        arr[i]=ar[i];
    }
   
}

void insert(A x)
{
// if(listSize==maxSize)
// {
//     A *a = new A[maxSize];
//         for(int i=0;i<listSize;i++)
//         {
//             a[i]=arr[i];
//         }
//         maxSize += sizeIncrease;
//         arr=new A[maxSize];
//         for(int i=0;i<listSize;i++)
//         {
//             arr[i]=a[i];
//         }

//         delete [] a;
// }
//     for(int i=listSize; i>curr; i--)
//     {
//         arr[i]=arr[i-1];
//     }
    arr[curr]=x;
    listSize++;
}
A remove( )
{  
     A x=arr[curr];
    for(int i=curr; i<listSize-1; i++)
    {
        arr[i]=arr[i+1];
    }
   listSize--;
    return x;
}
void movetoStart()
{
    curr=0;
}
void movetoEnd()
{
    curr=listSize-1;
}
void prev()
{
    if(curr!=0)
    {
        curr--;
    }
}
void next()
{ 
  curr++;

}
int length()
{
    return listSize;
}
int currPos()
{
    return curr;
}
void moveToPos(int pos)
{
    
        curr=pos;
    

}
A getvalue()
{    
  return arr[curr];
}
void print()
{
    if(length()==0)
    {
        cout<<"<>"<<endl;
    }
    else
    {
    cout<<"<";
    for(int i=0; i<curr; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"|";
    for(int i=curr; i<listSize; i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<">"<<endl;
    }
}
};
