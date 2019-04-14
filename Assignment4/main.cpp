#include <iostream>
#include "./Tests/TestingClass.h"
#include "./Tests/ShortTest.h"
#include "./Tests/ExtendedTest.h"
int main()
{
    TestingClass test;
    test.testDoubleLinkedListOnArray();
    testAll();
    testAllExtended();
    return 0;
}