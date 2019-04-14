//
// Created by Vlad on 13-Apr-19.
//

#ifndef ASSIGNMENT4_DOUBLELINKEDLISTARRAY_H
#define ASSIGNMENT4_DOUBLELINKEDLISTARRAY_H

typedef int TElem;
class DoubleLinkedListArray
{
    class DLLANode
    {
        friend class DoubleLinkedListArray;
        //this might boom
        TElem info;
        int next;
        int prev;
    };

private:
    DLLANode *nodes;
    int capacity;
    int size;
    int head;
    int tail;
    int firstEmpty;

    int allocateNewElement();
    void doubleCapacity();

public:
    DoubleLinkedListArray();
    ~DoubleLinkedListArray();
    void insertPosition(TElem element, int position);
    void remove(int position);
    void insertAtEnd(TElem element);
    bool search(TElem element);




};


#endif //ASSIGNMENT4_DOUBLELINKEDLISTARRAY_H
