//
// Created by Vlad on 16-Mar-19.
//
#include <assert.h>
#include "personalTest.h"
#include "../DynamicArray.h"
#include <iostream>

void printArray(DynamicArray &da)
{
    int i;
    for(i=0;i<da.size();i++)
    {
        std::cout<<da.getElement(i)<<" ";
    }
    std::cout<<"\n";
}

void testDynamicArrayPersonal()
{
    DynamicArray da(4);
    assert(da.size() == 0);
    da.addToEnd(5);
    assert(da.size() == 1);
    da.addToPosition(1, 1);
    da.addToPosition(0, 10);
    da.addToPosition(1, 7);
    da.addToPosition(1, 1);
    da.addToPosition(1, 11);
    da.addToPosition(1, -3);

    assert(da.size() == 7);
    assert(da.remove(1) == -3);
    assert(da.remove(4) == 5);
    assert(da.size() == 5);
    assert(da.setElement(0, 7) == 10);
    assert(da.size() == 5);
}


