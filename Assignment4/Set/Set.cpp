//
// Created by Vlad on 13-Apr-19.
//

#include "Set.h"
#include "SetIterator.h"

Set::Set()
{

}

bool Set::add(TElem e)
{
    return false;
}

bool Set::remove(TElem e)
{
    return false;
}

bool Set::search(TElem elem) const
{
    return false;
}

int Set::size() const
{
    return 0;
}

bool Set::isEmpty() const
{
    return false;
}

SetIterator Set::iterator() const
{
    return SetIterator(*this);
}

Set::~Set()
{

}
