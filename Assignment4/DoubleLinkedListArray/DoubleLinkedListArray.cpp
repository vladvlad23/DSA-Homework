//
// Created by Vlad on 13-Apr-19.
//

#include <stdexcept>
#include "DoubleLinkedListArray.h"

void DoubleLinkedListArray::insertPosition(TElem element, int position)
{
    if(position>size || position<0)
        throw std::invalid_argument("Invalid position");
    int newPosition = allocateNewElement();
    nodes[newPosition].info = element;
    if(position==0)
    {
        if(head==-1)
        {
            head = newPosition;
            tail = newPosition;
        }
        else
        {
            nodes[newPosition].next = head;
            nodes[newPosition].prev = -1;
            nodes[head].prev = newPosition;
            head = newPosition;
        }
    }
    else
    {
        int currentNode = head;
        int currentPosition = 0;
        while(currentNode!=-1 && currentPosition < position -1) //while we are not at the end and not at the desired position
        {
            currentNode = nodes[currentNode].next;
            currentPosition++;
        }
        int nextNode = nodes[currentNode].next;
        nodes[newPosition].next = nextNode;
        nodes[newPosition].prev = currentNode;
        nodes[currentNode].next = newPosition;
        if(nextNode==-1)
            tail = nextNode;
        nodes[nextNode].prev = newPosition;
    }
    size++;
}

void DoubleLinkedListArray::remove(int position)
{
    int prevNode = head;
    int currentNode = head;
    int currentPosition = 0;
    while(currentPosition<position)
    {
        prevNode = currentNode;
        currentNode = nodes[currentNode].next;
        currentPosition++;
    }
    //we are behind the node that needs to be removed
    nodes[prevNode].next = nodes[currentNode].next; //the one before points to the one afte
    nodes[nodes[currentNode].next].prev = prevNode;

    //so, this isn't in the courses as pseudocode, so i have to note it so i know tf happened
    //this will practically make a list of empty spots to which we append the one we just freed
    nodes[currentNode].next=firstEmpty;
    nodes[currentNode].prev=-1;
    firstEmpty=currentNode;
}

void DoubleLinkedListArray::insertAtEnd(TElem element)
{
    int newPosition = allocateNewElement();
    nodes[newPosition].info = element;
    nodes[newPosition].next = -1;
    nodes[newPosition].prev = tail;
    if(tail !=-1)
        nodes[tail].next = newPosition;
    tail = newPosition;
    if(head==-1)
    {
        head = newPosition;
        tail = newPosition;
    }
    size++;
}

bool DoubleLinkedListArray::search(TElem element)
{
    int currentNode = head;
    DLLANode nod;
    while(currentNode!=-1)
    {
        nod = nodes[currentNode];
        if(nod.info == element)
            return true;
        currentNode = nodes[currentNode].next;
    }
    return false;

}

DoubleLinkedListArray::DoubleLinkedListArray()
{
    capacity = 5;
    size = 0;
    head = -1;
    tail = -1;
    firstEmpty = 0;
    nodes = new DLLANode[capacity];
    nodes[0].next = 1;
    nodes[0].prev = -1;
    for(int i=1;i<capacity-1;i++)
    {
        nodes[i].next=i+1;
        nodes[i].prev=i-1;
    }
    nodes[capacity-1].next=-1;
    nodes[capacity-1].prev=capacity-1;

}

DoubleLinkedListArray::~DoubleLinkedListArray()
{
    delete [] nodes;
}

void DoubleLinkedListArray::doubleCapacity()
{
    DLLANode *newNodes = new DLLANode[capacity*2];
    for(int i = 0;i<size;i++)
    {
        newNodes[i] = nodes[i];
    }
    for(int i = size;i<capacity*2-1;i++)
    {
        newNodes[i].next=i+1;
        newNodes[i].prev=-1;
    }
    newNodes[(capacity*2)-1].next=-1;
    delete [] nodes;
    capacity*=2;
    if(firstEmpty==-1)
        firstEmpty=size;
    nodes = newNodes;
}

int DoubleLinkedListArray::allocateNewElement()
{
    int newElement = firstEmpty;
    if (newElement!=-1)
    {
        firstEmpty = nodes[firstEmpty].next;
        if (firstEmpty!=-1)
        {
            nodes[firstEmpty].prev=-1;
        }
    }
    else
    {
        doubleCapacity();
        return allocateNewElement();
    }
    return newElement;
}
