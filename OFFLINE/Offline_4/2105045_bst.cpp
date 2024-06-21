#include<bits/stdc++.h>
using namespace std;
template <typename B>
struct NODE
{
    B key;
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
    ofstream outfile;
    NODE<B> *InsertHelper(NODE<B> *node,B value)
    {
        if(node==nullptr)
        {
            return new NODE<B>(value);
        }
        if(value<node->key)
        {
            node->left=InsertHelper(node->left,value);
        }
        else if(value>node->key)
        {
            node->right=InsertHelper(node->right,value);
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
        InOrder(node->left);
        outfile<<node->key<<" ";
        InOrder(node->right);
    }
    void PreOrder(NODE<B> *node)
    {
        if(node==nullptr)
        {
            return ;
        }
        outfile<<node->key<<" ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
    void PostOrder(NODE<B> *node)
    {
        if(node==nullptr)
        {
            return ;
        }
        PostOrder(node->left);
        PostOrder(node->right);
        outfile<<node->key<<" ";
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
        if(data<node->key)
        {
            node->left=RemoveHelper(node->left,data);
        }
        else if(data>node->key)
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
                //return node;
            }
            //case-2:Node to be deleted only has one child
            
            
               else if(node->left==nullptr)
                {
                    NODE<B> *temp=node;
                    node=node->right;
                    delete temp;
                    //return node;
                }
               else  if(node->right==nullptr)
                {
                    NODE<B> *temp=node;
                    node=node->left;
                    delete temp;
                    //return node;
                }
            //case-3:Node to be deleted has two children
               else
                {
                NODE<B> *temp=inorder_successor(node->right);
                node->key=temp->key;
                node->right=RemoveHelper(node->right,temp->key);
                //return node;
                }
        }
        return node;

        
    }
    // NODE<B> count(NODE<B> *node)
    // {
    //     if(node==null)
    //     {
    //         return;
    //     }
    //     return 1+count(node->left)+count(node->right);
    // }
    
    void PrintHelper(NODE<B> *node)
    {    
        if(node!=nullptr)
        {
            outfile<<node->key;
            if(node->left || node->right)
            {
                outfile<<"(";
                PrintHelper(node->left);
                outfile<<",";
                PrintHelper(node->right);
                outfile<<")";
            }
            //cout<<")";
        }
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
    // void CountNode()
    // {
    //     count(root);
    // }


};