#include<bits/stdc++.h>
#include"Stack.cpp"
using namespace std;


int main()
{
    string data;
    cout<<"What data type of the stack you want to implement(int/char) "<<endl;
    cin>>data;
    if (data=="int")
    {   int K,X,V,ans;
        cin>>K>>X;
        Stack<int>A(X);
        for(int i=0;i<K;i++)
        {
          cin>>V;
          A.push(V);
        }
        int Q,P;
        cin>>Q;
        while(Q)
        { 
            cin>>P;
        switch(Q)
        {
            case 1:
                  A.clear();
                  A.print();
                  break;
            case 2:
                 A.push(P);
                 A.print();
                 break;
            case 3:
                ans=A.pop();
                A.print();
                cout<<ans<<endl;
                break;
            case 4:
                ans=A.length();
                A.print();
                cout<<ans<<endl;
                break;
            case 5:
                ans=A.topvalue();
                A.print();
                cout<<ans<<endl;
                break;
            case 6:
               A.print();
               cout<<boolalpha<< A.isEmpty()<<endl;
                break;
        }
        cin>>Q;
        }
        
    }
     else  if (data=="char")
    {   int K,X;
        char V,ans;
        cin>>K>>X;
        Stack<char>C(X);
        for(int i=0;i<K;i++)
        {
          cin>>V;
          C.push(V);
        }
        int Q;
        char P;
        cin>>Q;
        while(Q)
        { 
            cin>>P;
        switch(Q)
        {
            case 1:
                  C.clear();
                  C.print();
                  break;
            case 2:
                 C.push(P);
                 C.print();
                 break;
            case 3:
                ans=C.pop();
                C.print();
                cout<<ans<<endl;
                break;
            case 4:
                
                C.print();
                cout<<C.length()<<endl;
                break;
            case 5:
                ans=C.topvalue();
                C.print();
                cout<<ans<<endl;
                break;
            case 6:
                C.print();
                cout<<boolalpha<< C.isEmpty()<<endl;
                break;
        }
        cin>>Q;
        }
        
    }
}

