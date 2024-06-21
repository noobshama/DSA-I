#include<bits/stdc++.h>
#include"2105045_max_priority_queue.cpp"
using namespace std;
// void  merge(MaxHeap<int>pq1,MaxHeap<int>pq2)
// {    
//     MaxHeap<int>pq3;
//     int n2=pq2.SIZE();
//     for(int i=1;i<=n2;i++)
//     {
//         pq1.Insert(pq2.ExtractMax());
//     }
//     //pq1.print();
//     pq3=pq1;
//     pq3.print();
//     //return pq3;
// }
MaxHeap<int>merge(MaxHeap<int>pq1,MaxHeap<int>pq2)
{
    MaxHeap<int>pq3;
    int n2=pq2.SIZE();
    for(int i=1;i<=n2;i++)
    {
        pq1.Insert(pq2.ExtractMax());
    }
    //pq1.print();
    pq3=pq1;
    //pq3.print();
    return pq3;
}
int main()
{
    MaxHeap<int>pq1;
    MaxHeap<int>pq2;
    MaxHeap<int>pq3;
    int n1,n2;
    cin>>n1>>n2;
    int p,q;
    for(int i=1;i<=n1;i++)
    {
        cin>>p;
        pq1.Insert(p);
    }
    for(int i=1;i<=n2;i++)
    {
        cin>>q;
        pq2.Insert(q);
    }
    pq3=merge(pq1,pq2);
    pq3.print();
    // for(int i=1;i<=n2;i++)
    // {
    //     pq1.Insert(pq2.ExtractMax());
    // }
    // pq1.print();
}