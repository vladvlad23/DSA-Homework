//
// Created by Vlad on 14-Apr-19.
//

#include "TestingClass.h"

void TestingClass::testDoubleLinkedListOnArray()
{
    DoubleLinkedListArray list;
    list.insertAtEnd(10);
    assert(list.search(10));
    list.insertAtEnd(20);
    assert(list.search(20));
    list.insertAtEnd(30);
    assert(list.search(30));
    list.insertAtEnd(40);
    assert(list.search(40));
    list.insertPosition(15,1);
    assert(list.search(15));
    list.insertPosition(25,3);
    assert(list.search(25));
    list.insertPosition(35,5);
    assert(list.search(35));
    list.insertPosition(5,0);
    assert(list.search(5));
    assert(list.search(40));
    assert(list.getSize() == 8);

    //########## Test removal ##########

    list.removeByNodePosition(2);
    assert(list.getSize() == 7);
    assert(!list.search(30));
    assert(list.search(40));

    list.removeByNodePosition(0);
    assert(list.getSize() == 6);
    assert(!list.search(10));

    list.insertAtEnd(30);
    assert(list.search(30));



}
