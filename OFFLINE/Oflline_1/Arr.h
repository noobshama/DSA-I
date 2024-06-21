#ifndef ARR_H
#define ARR_H

class LINK
{
    int maxSize;
    int listSize;
    int sizeIncrease;
    int curr;
    int *arr;
public:
    void init (int,int,int*);
    LINK();
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