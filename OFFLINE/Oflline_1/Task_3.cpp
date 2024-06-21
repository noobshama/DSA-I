#include<bits/stdc++.h>
#include "Arr.cpp"
//#include "List.cpp"
using namespace std;
int main()
{  int min,max,MIN,MAX;
    LINK gar[100];
    int x,y,z;
    cin>>x>>y>>z;
    for(int i=0;i<y;i++)
    {
        int p;
        int g;
        cin>>g;
        cin>>p;
        int a[p+1];
        for(int j=0;j<p;j++)
        {
            cin>>a[j];
        }
        gar[g-1].init(z,p,a);
    }
    int a1[100];
    while(1)
    {
        char str[10];
        cin>>str;
        if(strcmp(str,"end"))
        {   exit(0);
            break;
        }
        else if (strcmp(str,"req"))
        {     int j=0;
        int indx;
        min=INT_MAX;
        max=INT_MIN;
        MIN=INT_MAX;
        MAX=INT_MIN;
        int count=0; 
               for(int i=0;i<y;i++)
               {
                if(gar[i].length()!=0)
                {
                    a1[j]=i;
                    j++;
                    count++;
                }
               }
               for(int i=0;i<count;i++)
               {
                if (a1[i]<min)
                {
                       min=a1[i];
                }
               }
                for(gar[min].movetoStart();gar[min].currPos()<gar[min].length();gar[min].next())
                {  
                    if(gar[min].getvalue()<MIN)
                    {
                          MIN=gar[min].getvalue();
                          indx=gar[min].currPos();
                    }     
                }
                gar[min].movetoStart();
                gar[min].moveToPos(indx);
                gar[min].remove();
                cout<<min<<" ";
                for(gar[min].movetoStart();gar[min].currPos()<gar[min].length();gar[min].next())
            {
                cout<<gar[min].getvalue()<<" ";
            }
            
        }
        else if(strcmp(str,"ret"))
        {
            int car;
            cin>>car;
            int j=0;
        int indx;
        min=INT_MAX;
        max=INT_MIN;
        MIN=INT_MAX;
        MAX=INT_MIN;
        int count=0; 
               for(int i=0;i<y;i++)
               {
                if(gar[i].length()<z)
                {
                    a1[j]=i;
                    j++;
                    count++;
                }
                }
                for(int i=0;i<count;i++)
               {
                if (a1[i]>max)
                {
                       max=a1[i];
                }
               }
                for(gar[max].movetoStart();gar[max].currPos()<gar[max].length();gar[max].next())
                {  
                    if(gar[max].getvalue()>MAX)

                    { 
                         MAX=gar[max].getvalue();
                         indx=gar[max].currPos();
                    }     
                }
                gar[max].movetoStart();
                gar[max].moveToPos(indx);
                gar[max].next();
                gar[max].insert(car);
              //  cout<<4<<endl;
                cout<<max<<" ";
                for(gar[max].movetoStart();gar[max].currPos()<gar[max].length();gar[max].next())
            {
                cout<<gar[max].getvalue()<<" ";
            }
            
      }
     
}
  return 0;
}