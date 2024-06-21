#include<bits/stdc++.h>
#include "List.h"
using namespace std;

void LINK:: init(int size1,int size2,int *ar)
{      
    size=size2;
    head=(node*)malloc(sizeof(node));
    curr=tail=head;
       
    for(int i=0;i<size;i++)
    { 
      curr->next = (node*)malloc(sizeof(node));
      curr->next->data = ar[i];
      curr = curr->next;
      tail = curr;
     }
     tail->next = NULL;
     curr = head;
}
void LINK:: insert(int x)
{   
    node *newnode =(node*)malloc(sizeof(node));
    if(tail==curr )
    {
        tail->next=newnode;
        newnode->data=x;
        newnode->next=NULL;
        tail=newnode;
     }
    else
    {
         newnode->data=x;
         newnode->next=curr->next;
         curr->next=newnode;
     }
} 
int LINK:: remove()
{
    int x =curr->next->data;
    node *newnode=(node*)malloc(sizeof(node));
    newnode=curr->next;
    
  if(tail==curr->next)
   {  tail=curr;
      curr->next=NULL;
      free(newnode);
      return x;
   }
   else
   {
      curr->next=curr->next->next;
      free(newnode); 
      return x;
   }
   
}
void LINK:: movetoStart()
{
    curr=head;
}
void LINK::movetoEnd()
{
    
    curr=head;
    while(curr->next!=tail)
    {
        curr=curr->next;
    }
    
}
void LINK:: prev()
{
    node *newnode =(node*)sizeof(node);
     newnode=head;
    if(length()!=0)
     {
    while(newnode->next!=curr)
    {
        newnode=newnode->next;
    }
    curr=newnode;
     }
}
void LINK:: next()
{
   if (curr->next!=NULL)
        curr=curr->next;
    
    
    
}
int LINK:: length()
{
    int count=0;
    node *newnode=(node*)malloc(sizeof(node));
    newnode=head;
    while(newnode->next!=NULL)
    {
        count++;
        newnode=newnode->next;
    }
    return count;
}
int LINK:: currPos()
{
    node *newnode=(node*)malloc(sizeof(node));
     newnode=head;
     int i;
     for(i=0;newnode!=curr;i++)
     {
        newnode=newnode->next;
     }
     return i;
}
void LINK:: moveToPos(int pos)
{
    if((pos<=0)&& (pos>=length()))
    {
        return;
    }
    curr=head;
    if(length()!=0)
    {
    for(int i=0;i<pos;i++)
    {
    curr=curr->next;
    }
    }
}
int LINK:: getvalue()
{   
    if(length()!=0)
    {
    return curr->next->data;
    }
    else 
    {
        return -1;
    }
}
void LINK:: print()
 {
    if(length()==0)
    {
        cout<<"<>"<<endl;
    }
    else
    {
        node *temp=(node*)malloc(sizeof(node));
        temp=head;
        cout<<"<";
    while(temp!=curr)
    {   cout<<temp->next->data<<" ";
        temp=temp->next;
    }
        cout<<"|";
 while(temp!=tail)
 {
        cout<<temp->next->data<<" ";
        temp=temp->next;

 }  
  
cout<<">"<<endl;
    }

 }



    
