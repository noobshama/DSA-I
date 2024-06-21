#include<bits/stdc++.h>
//#include "Arr.h"
#include "List.cpp"
using namespace std;


int main()
{
    LINK a;
    int k,x,y,z,h;
    cin>>k>>x;

    int arr1[k];
    for(int i=0; i<k; i++)
    {
        cin>>arr1[i];
     }
    a.init(x,k,arr1);
    a.print();
    int Q,P;
    cin>>Q;
     while(Q)
    {
        cin>>P;
        switch(Q)
        {
        case 1:
            a.insert(P);
            a.print();
            break;
        case 2:
            cout<< a.remove()<<endl;
            a.print();
            break;
        case 3:
            a.movetoStart();
            a.print();
            break;
        case 4:
            a.movetoEnd();
            a.print();
            break;
        case 5:
            a.prev();
            a.print();
            break;
        case 6:
            a.next();
            a.print();
            break;
        case 7:
            z= a.length();
            cout<<z<<endl;
            a.print();
            break;
        case 8:
            h= a.currPos();
           cout<<h<<endl;
            a.print();
            break;
        case 9:
         a.moveToPos(P);
          a.print();
            break;
        case 10:
            y= a.getvalue();
            cout<<y<<endl;
            a.print();
            break;
        default:
            cout<<"nothing"<<endl;

        }

        cin>>Q;
    }

    return 0;
}
