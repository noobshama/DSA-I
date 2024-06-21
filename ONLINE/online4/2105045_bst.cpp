#include<bits/stdc++.h>
using namespace std;
template <typename B>
struct NODE
{
    B key;
    B nodecount;
    NODE<B> *left;
    NODE<B>*right;
    NODE(B key1)
    {
        key=key1;
        left=nullptr;
        right=nullptr;
    }
};
template <typename B>
class BST
{
    NODE<B> *root;
    //int nodecount=1;
    int x=0;
    int y=0;
    int z=0;
    int u=0;
    ofstream outfile;
    NODE<B> *InsertHelper(NODE<B> *node,B value)
    {
        if(node==nullptr)
        {
            return new NODE<B>(value);
        }
       else if(value<=node->key )
        {   
             if(value==node->key)
             {  
                node->nodecount++;
                node->left=InsertHelper(node->left,value);
             }
             else if(value<node->key)
             {
                node->left=InsertHelper(node->left,value);
             }
        }
        else if(value>=node->key)
        {    
            if(value==node->key)
            {
                node->nodecount++;
                node->right=InsertHelper(node->right,value);
            }
            else if(value>node->key)
            {
                node->right=InsertHelper(node->right,value);
            }
        }
        return node;
    }
     NODE<B> *FindHelper(NODE<B>*node,B data)
    {    
        
        if(node==nullptr)
        {
            return node;
        }
         
       else if(node->key==data)
        {
            return node;
        }
        else if(data<node->key)
        {
            return FindHelper(node->left,data);
        }
        else if(data>node->key)
        {
            return FindHelper(node->right,data);
        }
        
    }
    void InOrder(NODE<B>*node)
    {
        if(node==nullptr)
        {
            return;
        }
        if(node->nodecount!=1)
        {
        InOrder(node->left);
        //z=node->key;
        outfile<<node->key<<" "<<"["<<nodecount<<"]"<<" ";
        InOrder(node->right);
        //z=node->key;
        }
        else if(node->nodecount==1)
        {
            InOrder(node->left);
            outfile<<node->key<<" ";
            InOrder(node->right);
        }
    }
    void PreOrder(NODE<B> *node)
    {
        if(node==nullptr)
        {
            return ;
        }
        if(node->nodecount!=1  )
        {
        outfile<<node->key<<" "<<"["<<nodecount<<"]"<<" ";
        PreOrder(node->left);
       // y=node->key;
        PreOrder(node->right);
        //y=node->key;
        }
        else if(node->nodecount==1)
        {
            outfile<<node->key<<" ";
            PreOrder(node->left);
            PreOrder(node->right);
        }
        //y=node->key;
    }
    void PostOrder(NODE<B> *node)
    {
        if(node==nullptr)
        {
            return ;
        }
        if(node->nodecount!=1 )
        {
        PostOrder(node->left);
        //u=node->key;
        PostOrder(node->right);
        //u=node->key;
        outfile<<node->key<<" "<<"["<<nodecount<<"]"<<" ";
        
        }
        else if(node->nodecount==1)
        {
            PostOrder(node->left);
        PostOrder(node->right);
        outfile<<node->key<<" ";
        }
    }
    NODE<B> *inorder_successor(NODE<B> *node)
    {
        while( (node!=nullptr) && (node->left!=nullptr))
        {
            node=node->left;
        }
        return node;
    }
    NODE<B> *RemoveHelper(NODE<B> *node,B data)
    {
        if(node==nullptr)
        {
            return node;
        }
        if(data<=node->key)
        {   
            node->left=RemoveHelper(node->left,data);
            
        }
        else if(data>=node->key)
        {   
            node->right=RemoveHelper(node->right,data);
         }
        else
        {
            //case-1:Node to be deleted is the leaf
            if(node->left==nullptr && node->right==nullptr)
            {
                delete node;
                node=nullptr;
                node->nodecount--;
                //return node;
            }
            //case-2:Node to be deleted only has one child
            
            
               else if(node->left==nullptr)
                {
                    NODE<B> *temp=node;
                    node=node->right;
                    delete temp;
                    node->nodecount--;
                    //return node;
                }
               else  if(node->right==nullptr)
                {
                    NODE<B> *temp=node;
                    node=node->left;
                    delete temp;
                   node->nodecount--;
                    //return node;
                }
            //case-3:Node to be deleted has two children
               else
                {
                NODE<B> *temp=inorder_successor(node->right);
                node->key=temp->key;
                node->right=RemoveHelper(node->right,temp->key);
                node->nodecount--;
                //return node;
                }
        }
        return node;

        
    }
    
    void PrintHelper(NODE<B> *node)
    {    
        //int x=node->key;
        if(node!=nullptr)
        {   
            if(node->nodecount!=1)
            {
            outfile<<node->key<<" "<<"["<<node->nodecount<<"]";
            if(node->left || node->right)
            {
                outfile<<"(";
                PrintHelper(node->left);
               // x=node->key;
                outfile<<",";
                PrintHelper(node->right);
                //x=node->key;
                outfile<<")";
                //x=node->key;
            }
            }
            else if(nodecount==1)
            {
                outfile<<node->key<<" ";
            if(node->left || node->right)
            {
                outfile<<"(";
                PrintHelper(node->left);
                outfile<<",";
                PrintHelper(node->right);
                outfile<<")";
            }
            }
            //cout<<")";
        }
         //x=node->key;
        //cout<<")";
    }
    public:
    BST()
    {
        root=nullptr;
        outfile.open("out.txt");
        if(!outfile.is_open())
        {
            cout<<"file can't be open"<<endl;
        }
        outfile.clear();

    }
    ~BST()
    {
        outfile.close();
    }
    void insert(B data)
    {
        root=InsertHelper(root,data);

    }
    void find(B data)
    {
        NODE<B>*temp=FindHelper(root,data);
         if(temp!=nullptr)
         {
            outfile<<"found"<<endl;
         }
         else
         {
            outfile<<"not found"<<endl;
         }
    }
    void traverse(string s)
    {
        if(s=="In")
        {
            InOrder(root);
        }
       else if(s=="Pre")
        {
            PreOrder(root);
        }
       else if(s=="Post")
        {
            PostOrder(root);
        }
        outfile<<endl;
    }
    void remove(B data)
    {
        root=RemoveHelper(root,data);
    }
    void print()
    {   
        outfile<<"(";
        PrintHelper(root);
        outfile<<")";
        outfile<<endl;
    }


};