#include<bits/stdc++.h>
#include"Stack.cpp"
using  namespace std;
Stack<double>value;
bool isdigit(char c)
{
    if(c>='0' && c<='9')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
bool isopt(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
} 
double result (int v,int v1,char c)
{
    if(c=='+')
    {
        return v+v1;
    }
    if(c=='-')
    {
        return v-v1;
    }
    if(c=='*')
    {
        return v*v1;
    }
    if(c=='/')
    {
        return v/v1;
    }
}
  
int calculation (string s1)
{
    // Stack<double>value;
    //Stack<char>opt;
    double val=0;
    int v,v1;
    int pos=0;
    int indx=0;
    while(pos<s1.length())
    {   
       char p=s1[indx];
       if(isdigit(p))
       {   
         value.push(p-'0');
       }
       else if (isopt(p))
       {
         v=value.pop();
         v1=value.pop();
         val=result(v1,v,p);
         value.push(val);
       }
       indx++;
       //return val;
       
    }
    return value.pop();
    
}
int main()
{
    string s;
    double ans;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    cin>>s;
    ans =calculation(s);
    }
    
    //ans =calculation(s);
    cout<<ans<<endl;
}
