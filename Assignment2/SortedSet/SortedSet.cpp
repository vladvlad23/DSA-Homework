//
// Created by Vlad on 29-Mar-19.
//

#include <stdexcept>
#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r)
{
    relation = r;
}

bool SortedSet::add(TComp e)
{
    //LinkedListIterator it = list.iterator(); //iterator for list
    if(!list.getHead())
    {
        list.setHead(new Node(e));
        return true;
    }
    Node *prevNode = list.getHead();
    if(prevNode->information == e)
        return false;

    if(!relation(prevNode->information,e)) // means we have to change head
    {
        if(prevNode->information!=e)
        {
            list.addAfter(list.getHead(),list.getHead()->information);
            list.setHead(new Node(e));
            return true;
        }
        else
            return false;
    }
    Node *currentNode = prevNode->next;
    for(int i=1;i<list.size() && relation(currentNode->information,e);i++)
    {
        prevNode = currentNode;
        if(prevNode->information == e)
            return false;
        currentNode = currentNode->next;
    }

/*
    while(it.valid() && relation(it.getCurrent(),e))
    {
        if(it.valid())
            prevNode = it.getCurrentNode();
        else
        {
            list.addAfter(prevNode, e);
            return true;
        }
        it.next();
    }
*/
    if(prevNode->next)
        if(prevNode->next->information == e)
            return false;
    list.addAfter(prevNode, e);
    return true;
}

bool SortedSet::remove(TComp e)
{
    if(!list.search(e))
        return false;
    list.remove(e);
    return true;
}

bool SortedSet::search(TElem elem) const
{
    return (list.search(elem) != nullptr);
}

int SortedSet::size() const
{
    return list.size();
}

bool SortedSet::isEmpty() const
{
    return list.isEmpty();
}

SortedSetIterator SortedSet::iterator() const
{
    return SortedSetIterator(*this);
}

SortedSet::~SortedSet()
{

}