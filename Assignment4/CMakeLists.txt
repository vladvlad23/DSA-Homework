cmake_minimum_required(VERSION 3.10)
project(Assignment4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment4 main.cpp
        Set/Set.cpp Set/Set.h
        Tests/ExtendedTest.cpp Tests/ExtendedTest.h
        Tests/ShortTest.h Tests/ShortTest.cpp Set/SetIterator.cpp Set/SetIterator.h DoubleLinkedListArray/DoubleLinkedListArray.cpp DoubleLinkedListArray/DoubleLinkedListArray.h Tests/TestingClass.cpp Tests/TestingClass.h DoubleLinkedListArray/DoubleLinkedListArrayIterator.cpp DoubleLinkedListArray/DoubleLinkedListArrayIterator.h)