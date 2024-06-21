#include<bits/stdc++.h>
#include"2105045_2_stack.cpp"

using namespace std;
template<typename S>
void templates(Stack<S>St)
{   
    cout<<"Make a choice"<<endl;
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Length"<<endl;
    cout<<"4.Topvalue"<<endl;
    cout<<"5.is_Empty"<<endl;
    cout<<"6.clear"<<endl;
    int Q;
     S ans,P;
    cin>>Q;
    while(Q)
    {
     switch(Q)
        {
        case 1:
            cin>>P;
            St.push(P);
            St.printt();
            break;
        case 2:
          ans= St.pop();
           St.printt(); 
           cout<<ans<<endl;
            break;
        case 3:
            St.printt();
            cout<<St.length()<<endl;
            break;
        case 4:
            ans=St.topvalue();
            St.printt();
            cout<<ans<<endl;
            break;
        case 5:
            St.printt();
            cout<<boolalpha<<St.is_Empty()<<endl;
            break;
            case 6:
            St.clear();
            St.printt();
            default:
            break;
        
        }

        cin>>Q;
    }
}
int main()
{   
    // 
    cout<<"what data type you want to use?"<<endl;
    cout<<"1.int"<<endl;
    cout<<"2.float"<<endl;
    cout<<"3.double"<<endl;
    cout<<"4.char"<<endl;
    int C;
    cin>>C;
    if(C==1)
           
           {  
             Stack<int>STK;
             templates( STK);
           } 
           else if(C==2) 
           { 
            Stack<float>STK;
            templates(STK);
           }
           else if(C==3) 
           { 
            Stack<double>STK;
           templates(STK);
           }
           else if(C==4) 
           { 
            Stack<char>STK;
           templates(STK);
           }
}