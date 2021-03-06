//
// Created by Vlad on 13-Apr-19.
//

#ifndef ASSIGNMENT4_SETITERATOR_H
#define ASSIGNMENT4_SETITERATOR_H
#include "Set.h"
#include "../DoubleLinkedListArray/DoubleLinkedListArrayIterator.h"

//unidirectional iterator for a container

class SetIterator {
    friend class Set;

private:

    //Constructor receives a reference of the container.

    //after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty

    SetIterator(const Set& c);



    //contains a reference of the container it iterates over

    const Set& c;
    DoubleLinkedListArrayIterator listIterator;



    /* representation specific for the iterator*/



public:



    //sets the iterator to the first element of the container

    void first();



    //moves the iterator to the next element

    //throws exception if the iterator is not valid

    void next();



    //checks if the iterator is valid

    bool valid() const;



    //returns the value of the current element from the iterator

    // throws exception if the iterator is not valid

    TElem getCurrent() const;



};





#endif //ASSIGNMENT4_SETITERATOR_H
