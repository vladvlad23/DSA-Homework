//
// Created by Vlad on 29-Mar-19.
//

#include <stdexcept>
#include "TElemLinkedList.h"
#include "LinkedListIterator.h"

Node *TElemLinkedList::getHead() const
{
    return head;
}

void TElemLinkedList::setHead(Node *head)
{
    if(!TElemLinkedList::head)
    {
        TElemLinkedList::head = head;
        TElemLinkedList::numberOfElements = 1;
        return;
    }
    head->next = TElemLinkedList::head->next;
    delete (TElemLinkedList::head);
    TElemLinkedList::head = head;
}

Node * TElemLinkedList::search(TElem elementToBeSearched) const
{
    Node *node = head;
    while(node != nullptr)
    {
        if(node->information == elementToBeSearched)
            return node;
        node = node->next;
    }
    return nullptr;
}

//add to the end
void TElemLinkedList::add(TElem elementToBeAdded)
{
    Node *node = head;
    if(node == nullptr)
    {
        head = new Node(elementToBeAdded);
        numberOfElements++;
        return;
    }
    while(node->next)
    {
        node = node->next;
    }
    node->next = new Node(elementToBeAdded);
    numberOfElements++;
}

void TElemLinkedList::addAfter(Node *currentNode, TElem elementToBeAdded)
{
    if(!head)
    {
        head = new Node(elementToBeAdded);
        numberOfElements++;
        return;
    }
    Node *node = new Node(elementToBeAdded);
    node->next = currentNode->next;
    currentNode->next = node;
    /*
    Node *node = head;
    Node *prevNode = head;
    while(node != currentNode)
    {
        prevNode = node;
        node = node->next;
    }
    if(!(node->next))
    {
        node->next = new Node(elementToBeAdded);
        numberOfElements++;
        return;
    }
    prevNode = node;
    node = new Node(elementToBeAdded);
    node->next = prevNode->next;
    prevNode->next = node;*/
    numberOfElements++;

}

void TElemLinkedList::remove(TElem elementToBeRemoved)
{
    Node *node = head;
    if(!head)
        throw std::invalid_argument("There are no elements\n");
    if(head->information == elementToBeRemoved)
    {
        head = head->next;
        free(node);
        numberOfElements--;
        return;
    }

    while( node->next != nullptr && node->next->information!= elementToBeRemoved)
    {
        node = node->next;
    }
    if(node->next)
    {
        Node *saveForFreeing = node->next;
        node->next = node->next->next;
        delete saveForFreeing;
    }
    else
    {
        delete node->next;
        node->next = nullptr;
    }
    numberOfElements--;
}

TElem TElemLinkedList::getElement(int position) const
{
    int i;
    if(!head)
        throw std::invalid_argument("There is no such position\n");
    Node *node = head;
    for(i=0;i<position;i++)
    {
        if(!(node->next))
        {
            throw std::invalid_argument("There is no such position\n");
        }
        node = node->next;
    }
    return node->information;

}

LinkedListIterator TElemLinkedList::iterator() const
{
    return LinkedListIterator(*this);
}

TElemLinkedList::TElemLinkedList(TElem firstElement)
{
    head = new Node(firstElement);
    numberOfElements = 0;
}

TElemLinkedList::~TElemLinkedList()
{
    while(head)
    {
        Node *forDelete = head;
        head = head->next;
        delete forDelete;
    }
}

TElemLinkedList::TElemLinkedList()
{
    head = nullptr;
    numberOfElements = 0;

}

int TElemLinkedList::size() const
{
    return numberOfElements;
    /*
    if(!head)
        return 0;
    Node *node = head;
    int size=1;
    while(node->next!= nullptr)
    {
        size++;
        node = node->next;
    }
    return size;*/
}

bool TElemLinkedList::isEmpty() const
{
    return head == nullptr;
}

Node *TElemLinkedList::getNodeByPosition(int position) const
{
    int i;
    Node *node = head;
    for(i=0;i<position;i++)
    {
        if(!(node->next))
        {
            throw std::invalid_argument("There is no such position");
        }
        node = node->next;
    }
    return node;
};


