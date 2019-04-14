//
// Created by Vlad on 13-Apr-19.
//

#include <stdexcept>
#include "Set.h"
#include "SetIterator.h"

Set::Set()
{

}

bool Set::add(TElem e)
{
    if(elements.search(e))
        return false;
    elements.insertAtEnd(e);
    return true;
}

bool Set::remove(TElem e)
{
    int searchResult = elements.searchPosition(e);
    if(searchResult==-1)
        return false;
    elements.removeByNodePosition(searchResult);
    return true;
}

bool Set::search(TElem elem) const
{
    return elements.search(elem);
}

int Set::size() const
{
    return elements.getSize();
}

bool Set::isEmpty() const
{
    return elements.getSize()==0;
}

SetIterator Set::iterator() const
{
    return SetIterator(*this);
}

Set::~Set()
{

}