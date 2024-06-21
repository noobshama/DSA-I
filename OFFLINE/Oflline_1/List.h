#ifndef LIST_H
#define LIST_H
typedef struct  NODE 
{
    int data;
    NODE *next;
}node;
class LINK
{
    node *head,*tail,*curr;
  int size;
  public:
  void init(int ,int ,int *);
  void insert(int x);
   int remove( );
    void movetoStart();
    void movetoEnd();
    void prev();
    void next();
    int length();
    int currPos();
    void moveToPos(int);
    int getvalue();
    void print();
};
#endif