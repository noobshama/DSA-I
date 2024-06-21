#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        sum+=temp;
    }
    n++;
    int result=n*n-sum;
    cout<<result<<endl;
}