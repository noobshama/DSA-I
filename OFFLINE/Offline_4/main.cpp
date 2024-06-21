#include<bits/stdc++.h>
#include<iostream>
using namespace std;
template<typename P>
class MaxHeap{
  
  private:
    
    P *heap;
    int maxsize;
    int size;
    //ofstream outfile;
    void resize(int new_maxsize) {
        P *new_heap = new P[new_maxsize];
        for (int i = 1; i <= size; i++) {
            new_heap[i] = heap[i];
        }
        delete[] heap;
        heap = new_heap;
        maxsize = new_maxsize;
    }
    int parent(int i)
    {
        return i/2;
    }
    int left(int i)
    {
        return 2*i;
    }
    int right(int i)
    {
        return ((2*i)+1);
    }
    void InsertHelper(int i)
     {
        while(i>1 && heap[parent(i)]<heap[i])
        {
            P temp=heap[i];
            heap[i]=heap[parent(i)];
            heap[parent(i)]=temp;
            i=parent(i);
        }
     } 
     void max_heapify(int i)
     {
        int max_indx=i;
        int l=left(i);
        int r=right(i);
        if(l<=size && heap[l]>heap[max_indx])
        {
            max_indx=l;
        }
        
        if(r<=size && heap[r]>heap[max_indx])
        {
            max_indx=r;
        }
        if(max_indx!=i)
        {
            P temp=heap[i];
            heap[i]=heap[max_indx];
            heap[max_indx]=temp;
            max_heapify(max_indx);
        }

     }
    
    
     void BuildMaxHeap()
     {
        for(int i=size/2;i>=1;i--)
        {
            max_heapify(i);
        }
     }


     public:
      MaxHeap()
      {
         maxsize=1;
         heap=new P[maxsize];
         size=0;
         //outfile.open("out.txt");
        // if(!outfile.is_open())
        // {
        //     cout<<"file can't be open"<<endl;
        // }
        // outfile.clear();
         
      }
      MaxHeap(const MaxHeap& other) {
        maxsize = other.maxsize;
        size = other.size;
        heap = new P[maxsize];
        for (int i = 1; i <= size; i++) {
            heap[i] = other.heap[i];
        }
    }
    MaxHeap& operator=(const MaxHeap& other) {
        if (this != &other) {
            delete[] heap;
            maxsize = other.maxsize;
            size = other.size;
            heap = new P[maxsize];
            for (int i = 1; i <= size; i++) {
                heap[i] = other.heap[i];
            }
        }
        return *this;
    }
    ~MaxHeap() {
        delete[] heap;
    }
      void Insert(P i)
     {
        if(size==maxsize-1)
        {
            resize(maxsize*2);
        }
        size++;
        heap[size]=i;
      
        InsertHelper(size);
     }
     P FindMax()
     {
        //cout<<"Max: "<<heap[1]<<endl;;
        return heap[1];
     }
     P ExtractMax()
     {
      
      P max=heap[1];
      heap[1]=heap[size];
      size--;
      max_heapify(1);
      //outfile<<"Max: "<<max<<" has been extracted"<<endl;
      return heap[1];
     }
     void IncreaseKey(int i,P new_key)
     {
        if(heap[i]>new_key)
        {
            //outfile<<"New key is not larger than the previous key"<<endl;
            return;
        }
        
        heap[i]=new_key;
        InsertHelper(i);
        //outfile<<"Key increased!"<<endl;
        
     }
     void DecreaseKey(int i,P new_key)
     {  
         if(heap[i]<new_key)
        {
           // outfile<<"New key is not smaller than the previous key"<<endl;
            return;
        }
        heap[i]=new_key;
        max_heapify(i);
        //outfile<<"Key decreased!"<<endl;
     }
     
     void print()
     {   
        //outfile<<"No of elements: "<<size<<endl;
        // for(int i=1;i<=size;i++)
        // {
        //     cout<<heap[i]<<" ";
        // }
        
        int currentLevel = 1;
        int nodeprint = 1;
        for (int i = 1; i <= size; ++i)
        {
           cout<<heap[i].name<<heap[i].age<<"\t";

           nodeprint--;
           if (nodeprint == 0)
             {
               cout<< endl;
               currentLevel *= 2;
               nodeprint = currentLevel;
            }
        }

         cout<< endl;
     }
     void sort()
     {
        BuildMaxHeap();
        int n=size;
        for(int i=size;i>=2;i--)
        {
            P temp=heap[1];
            heap[1]=heap[i];
            heap[i]=temp;
           // n--;
           size--;
            max_heapify(1);
            
        }
        size=n;
     }








};


//using namespace std;
class Human {
public:
    string name;
    int age;

    Human() : name(""), age(0) {}  // Default constructor

    Human(string name, int age) : name(name), age(age) {}

    // Copy constructor
    Human(const Human& other) : name(other.name), age(other.age) {}

    // Copy assignment operator
    Human& operator=(const Human& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }
    bool operator<(const Human& other) const { return age < other.age; }
    bool operator>(const Human& other) const { return age > other.age; }
    bool operator<=(const Human& other) const { return age <= other.age; }
    bool operator>=(const Human& other) const { return age >= other.age; }
};
int main()
{
    MaxHeap<Human>heap;
    Human p1("Child", 5);
    Human p2("Grandfather", 70);
    Human p3("Older son", 20);
    Human p4("Father", 40);
    Human p5("Younger son", 10);

    //MaxHeap<Human> heap;

    heap.Insert(p1);
    heap.Insert(p2);
    heap.Insert(p3);
    heap.Insert(p4);
    heap.Insert(p5);
    heap.ExtractMax();
    heap.sort(); // Sort the MaxHeap

    heap.print(); // Print the sorted elements

    return 0;
}
