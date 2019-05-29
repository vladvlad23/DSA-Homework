//
// Created by Vlad on 29-May-19.
//

#include "TestBST.h"

void TestBST::testBST()
{
    BinarySearchTree<DummyNode> tree;
    DummyNode node;
    node.value = 11;
    tree.insertNode(node);

    node.value = 7;
    tree.insertNode(node);

    node.value = 2;
    tree.insertNode(node);

    node.value = 9;
    tree.insertNode(node);

    node.value = 4;
    tree.insertNode(node);

    node.value = 20;
    tree.insertNode(node);

    node.value = 19;
    tree.insertNode(node);

    node.value = 25;
    tree.insertNode(node);

    node.value = 15;
    tree.insertNode(node);

    node.value = 13;
    tree.insertNode(node);

    node.value = 17;
    tree.insertNode(node);



}
