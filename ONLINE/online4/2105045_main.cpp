#include<bits/stdc++.h>
#include"2105045_bst.cpp"
using namespace std;
int main()
{   
    ifstream infile("in1.txt");
    //ofstream outfile("out.txt");
    if(!infile.is_open())
    {
        cout<<"can't open the file"<<endl;
    }
    // if(!outfile)
    // {
    //     cout<<"can't open the file"<<endl;
    // }
    BST<int> bst;
    char ch;
    string t;
    //input>>ch;
    while(infile>>ch)
    {
        int p;
        if(ch=='I')
        {
            infile>>p;
            bst.insert(p);
            bst.print();
        }
        else if(ch=='F')
        {
            infile>>p;
            bst.find(p);
            //cout<<bst.find(p)<<endl;
        }
        else if(ch =='T')
        {   
            infile>>t;
            bst.traverse(t);
            //cout<<endl;
            //bst.print()
        }
        else if(ch =='D')
        {   
            infile>>p;
            bst.remove(p);
            bst.print();
            //cout<<endl;
        }
        //cin>>ch;
    }
    infile.close();
    //outfile.close();
    return 0;

}
