#include<bits/stdc++.h>
#include"List.cpp"
using namespace std;
int main()
{
    int m;
    cin>>m;
    int n;
    int arr[m+1];
    LINK ob1,ob2;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    ob1.init(m+1,m,arr);
    ob2.init(m+1,0,{});
    int p;
    ob1.movetoStart();
    ob2.movetoStart();
    for(int i=0;i<ob1.length()/2;i++)
    {
        //ob1.moveToPos(i);
        ob2.insert(ob1.getvalue());
        ob2.movetoEnd();
        ob2.next();
        ob1.moveToPos(ob1.length()-i-1);
        ob2.insert(ob1.getvalue());
        ob2.movetoEnd();
        ob2.next();
        ob1.moveToPos(i+1);

    }

}