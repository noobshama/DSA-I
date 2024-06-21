#include<bits/stdc++.h>
#include "Arr.h"
using namespace std;
void LINK::init (int size1,int size2, int *ar )
{
    maxSize=size1;
    sizeIncrease = size1;
    listSize=size2;
    curr=0;
    arr=(int*)malloc(sizeof(int)*size1);
    for(int i=0; i<listSize; i++)
    {
        arr[i]=ar[i];
    }
}
LINK::LINK()
{

}
void LINK::insert(int x)
{
if(listSize==maxSize)
{
    int* a = (int*)malloc(sizeof(int)*maxSize);
        for(int i=0;i<listSize;i++)
        {
            a[i]=arr[i];
        }
        maxSize += sizeIncrease;
        arr=(int*)malloc(sizeof(int)*maxSize);
        for(int i=0;i<listSize;i++)
        {
            arr[i]=a[i];
        }

        free(a);
}
    for(int i=listSize; i>curr; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[curr]=x;
    listSize++;
}
int LINK::remove( )
{
    if ((curr<0)|| (curr>=listSize))
    {
        return -1;
    }
    int   x=arr[curr];
    for(int i=curr; i<listSize-1; i++)
    {
        arr[i]=arr[i+1];
    }

    listSize--;
    return x;
}
void LINK::movetoStart()
{
    curr=0;
}
void LINK::movetoEnd()
{
    curr=listSize-1;
}
void LINK::prev()
{
    if(curr!=0)
    {
        curr--;
    }
}
void LINK::next()
{ 
if (curr<listSize)
{
   curr++;
}
}
int LINK::length()
{
    return listSize;
}
int LINK::currPos()
{
    return curr;
}
void LINK::moveToPos(int pos)
{
    if(pos>=0 && pos<listSize)
    {
        curr=pos;
    }

}
int LINK::getvalue()
{
    return arr[curr];
}
void LINK::print()
{
    if(listSize==0)
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