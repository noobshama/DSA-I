#include<bits/stdc++.h>
#include"2105045_1_ll_queue.cpp"
//#include"2105045_1_a_queue.cpp"
using namespace std;
template <typename L>
void templates(Queue<L>Qu)
    {
    cout<<"Make a choice"<<endl;
    cout<<"1.Enqueue"<<endl;
    cout<<"2.Dequeue"<<endl;
    cout<<"3.Length"<<endl;
    cout<<"4.Front"<<endl;
    cout<<"5.Rear"<<endl;
    cout<<"6.is_Empty"<<endl;
    cout<<"7.clear"<<endl;
    
        int Q;
        L ans,P;
    
    cin>>Q;
     while(Q)
    {
        
        switch(Q)
        {
        case 1:
            cin>>P;
            Qu.enqueue(P);
            Qu.print();
            break;
        case 2:
            
            // if(Qu.is_Empty())
            //   return ;
            //ans=Qu.dequeue();
            //Qu.print();
            cout<<Qu.dequeue()<<endl;
            Qu.print();
            break;
        case 3:
            Qu.print();
            cout<<Qu.length()<<endl;
            break;
        case 4:
            Qu.print();
            cout<<Qu.Front()<<endl;
            break;
        case 5:
            Qu.print();
            cout<<Qu.Rear()<<endl;
            break;
        case 6:
            Qu.print();
            cout<<boolalpha<<Qu.is_Empty()<<endl;
            break;
        case 7:
            Qu.clear();
            Qu.print();
            break;
            default:
            break;
        
        }

        cin>>Q;
    }
    }
int main()
{    


    
    // Queue<int>Qu;
    
    // int Q,P;
    // int ans;
    
    // cin>>Q;
    //  while(Q)
    // {
        
    //     switch(Q)
    //     {
    //     case 1:
    //     cin>>P;
    //         Qu.enqueue(P);
    //         Qu.print();
    //         break;
    //     case 2:
    //         ans=Qu.dequeue();
    //         Qu.print();
    //         cout<<ans<<endl;
            
    //         break;
    //     case 3:
    //         Qu.print();
    //         cout<<Qu.length()<<endl;
    //         break;
    //     case 4:
    //         Qu.print();
    //         cout<<Qu.Front()<<endl;
    //         break;
    //     case 5:
    //         Qu.print();
    //         cout<<Qu.Rear()<<endl;
    //         break;
    //     case 6:
    //         Qu.print();
    //         cout<<boolalpha<<Qu.is_Empty()<<endl;
    //         break;
    //     case 7:
    //         Qu.clear();
    //         Qu.print();
    //         break;
    //         default:
    //         break;
        
    //     }

    //     cin>>Q;
    // }
    cout<<"what data type you want to use?"<<endl;
    cout<<"1.int"<<endl;
    cout<<"2.float"<<endl;
    cout<<"3.double"<<endl;
    cout<<"4.char"<<endl;
    int C;
    cin>>C;
    // switch(C)
    //     {
    //     case 1:
    // if(C==1)
           
    //        { Queue<int>Que;
    //          templates(Que); 
    //        } 
    //        else if(C==2) 

            // break;
        // case 2:
            
        //     Queue<float>Que;
        //    templates(Que);
        //     break;
        // case 3:
        //     Queue<double>Que;
        //    templates(Que);
        //     break;
        // case 4:
        //     Queue<char>Que;
        //     templates(Que);
        //     break;
            
        
        // }
           if(C==1)
           
           {  
             Queue<int>Que;
             templates(Que); 
           } 
           else if(C==2) 
           { 
            Queue<float>Que;
            templates(Que);
           }
           else if(C==3) 
           { 
            Queue<double>Que;
           templates(Que);
           }
           else if(C==4) 
           { 
            Queue<char>Que;
           templates(Que);
           }



    return 0;
}

    

    

