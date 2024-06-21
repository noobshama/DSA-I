#include<bits/stdc++.h>
#include"2105045_max_priority_queue.cpp"
using namespace std;
// template<typename P>
// void templates (MaxHeap<P>pq)
// {
//     cout<<"Make a choice"<<endl;
//     cout<<"1.Insert"<<endl;
//     cout<<"2.FindMax"<<endl;
//     cout<<"3.ExtractMax"<<endl;
//     cout<<"4.IncreaseKey"<<endl;
//     cout<<"5.DecreaseKey"<<endl;
//     cout<<"6.Print"<<endl;
//     cout<<"7.Terminate"<<endl;
//     int Q,n;
//     P ans,p;
//     cin>>Q;
//     while(Q)
//     {
//         switch(Q)
//         {
//             case 1:
//             cin>>p;
//             pq.Insert(p);
//             //pq.print();
//             break;
//             case 2:
//             ans=pq.FindMax();
//             cout<<"Max: "<<ans<<endl;
//             break;
//             case 3:
//             ans=pq.ExtractMax();
//             cout<<"Max: "<<ans<<" has been extracted"<<endl;
//             break;
//             case 4:
//             cin>>n;
//             cin>>p;
//             pq.IncreaseKey(n,p);
//             break;
//             case 5:
//             cin>>n;
//             cin>>p;
//             pq.DecreaseKey(n,p);
//             break;
//             case 6:
//             pq.print();
//             break;
//             case 7:
//             pq.sort();
//             pq.print();
//             exit(0);
//             break;
//             default:
//             break;

//          }
//          cin>>Q;
//     }
// }
// int main()
// {
//     cout<<"what data type you want to use?"<<endl;
//     cout<<"1.int"<<endl;
//     cout<<"2.float"<<endl;
//     cout<<"3.double"<<endl;
//     cout<<"4.char"<<endl;
//     int C;
//     cin>>C;
//     if(C==1)
           
//            {  
//              MaxHeap<int>heap;
//              templates( heap);
//            } 
//            else if(C==2) 
//            { 
//             MaxHeap<float>heap;
//             templates(heap);
//            }
//            else if(C==3) 
//            { 
//             MaxHeap<double>heap;
//            templates(heap);
//            }
//            else if(C==4) 
//            { 
//             MaxHeap<char>heap;
//            templates(heap);
//            }
// }
int main()
{   
    ifstream infile("in2.txt");
    //ofstream outfile("out.txt");
    if(!infile.is_open())
    {
        cout<<"can't open the file"<<endl;
    }
    // if(!outfile)
    // {
    //     cout<<"can't open the file"<<endl;
    // }
    MaxHeap<int>pq;
    int choice,n;
    int ans;
    //input>>ch;
    while(infile>>choice)
    {
        int p;
        if(choice==1)
        {
            infile>>p;
            pq.Insert(p);
            
        }
        else if(choice==2)
        {
           pq.FindMax();
            
        }
        else if(choice==3)
        {   
            pq.ExtractMax();
        }
        else if(choice==4)
        {   
            infile>>n;
            infile>>p;
            pq.IncreaseKey(n,p);
        }
        else if(choice==5)
        {   
            infile>>n;
            infile>>p;
            pq.DecreaseKey(n,p);
        }
        else if(choice==6)
        {   
            pq.print();
        }
        else if(choice==7)
        {   
            pq.sort();
            pq.print();
            exit(0);
        }
        //cin>>ch;
    }
    infile.close();
    //outfile.close();
    return 0;

}
