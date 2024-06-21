#include<bits/stdc++.h>
using namespace std;
template <typename L>
 struct  NODE 
{
    L data;
    NODE *next;
};
template <typename L>
class LINK
{ 
    NODE<L> *head,*tail,*curr;
    int size;
    public:

    
    void init(int size2)
    {
    size=size2;
    head= new NODE<L>;
    curr=tail=head;
    }
    LINK()
    {
        init(0);
    }
     
     
    void insert(L x)
{  
    NODE<L> *newnode=new NODE<L>;
    newnode->data=x;
    if(tail==curr)
    {
        tail->next=newnode;
        newnode->next=NULL;
        tail=newnode;
    }
    else
    {
        //cout<<"sadia"<<endl;
         newnode->next=curr->next;
         curr->next=newnode;
    } 
    
} 
L remove()
{
    L x =curr->next->data;
    NODE<L> *newnode;
    newnode=new NODE<L>;
    newnode=curr->next;
    
  if(tail==curr->next)
   {  tail=curr;
      curr->next=NULL;
      delete newnode;
      return x;
   }
   else
   {
      curr->next=curr->next->next;
      delete newnode;
      return x;
   }
   
}
void  movetoStart()
{
    curr=head;
}

void movetoEnd()
{
    curr=head;
    if(head!=tail)
    {
        while(curr->next!=tail)
        {
            curr=curr->next;
        }
        return;
    }
}
void  prev()
{
    NODE<L> *newnode ;
    newnode =new NODE<L>;
     newnode=head;
     
    while(newnode->next!=curr)
    {
        newnode=newnode->next;
    }
    curr=newnode;
     
}
void  next()
{
    // 
    // if(curr!=tail)
    // 
    if(curr==tail)
    {
        return;
    }
    curr=curr->next;
    // }
    
}
int length()
{
    int count=0;
    NODE<L> *newnode;
    newnode=new NODE<L>;
    newnode=head;
    while(newnode->next!=NULL)
    {
        count++;
        newnode=newnode->next;
    }
    return count;
}
int  currPos()
{
    NODE<L> *newnode;
    newnode=new NODE<L>;
     newnode=head;
     int i;
     for(i=0;newnode!=curr;i++)
     {
        newnode=newnode->next;
     }
     return i;
}
void  moveToPos(int pos)
{
    if((pos<=0)&& (pos>=length()))
    {
        return;
    }
    curr=head;
    
    for(int i=0;i<pos;i++)
    {
    curr=curr->next;
    }
    
}
L  getvalue()
{    
    
    return curr->next->data;
    
}
void  print1()
 {
    
        NODE<L> *temp;
        temp=new NODE<L>;
        if(length()==0)
        {
            cout<<"<>"<<endl;
        }
        else
        {
        temp=head;
        cout<<"<";
        while(temp!=tail)
   {
        cout<<temp->next->data<<" ";
        temp=temp->next;
   }  
 
       cout<<">"<<endl;
        }
    
}


};
