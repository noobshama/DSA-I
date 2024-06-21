 #include<bits/stdc++.h>
//#include "Arr.cpp"
#include "List.cpp"
using namespace std;
LINK A;
void clear()
{    
    for(A.movetoStart();A.currPos()<A.length();)
    {
          A.remove();
          
    } 
}
void append(int k)
{   
    A.movetoEnd();
    A.next();
    A.insert(k);
}
int search(int k)
{
    int y;
    for(A.movetoStart();A.currPos()<A.length();A.next())
    {
        if(k==A.getvalue())
        {
            y=A.currPos();
        }

    }
    return y;
}

int main()
{ 

    int k,x,z;
    cin>>k>>x;
    int arr1[k];
    for(int i=0; i<k; i++)
    {
        cin>>arr1[i];
        // a.init(x,k,arr1);
    }
    A.init(x,k,arr1);
    int Q,P;
    cin>>Q;
    while(Q)
    {
        cin>>P;
        
        switch(Q)
        {
        case 1:
            clear();
            A.print();
            break;
        case 2:
            
            append(P);
            A.print();
            break;
        case 3:
           z= search(P);
           cout<<z<<endl;
           A.print();
            break;
        default:
        cout<<"nothing"<<endl;
        }
        cin>>Q;
    }
}
