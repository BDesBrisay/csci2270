#include <iostream>
#include "./BST.h"

using namespace std;

int main() {
    BST tree(10);

    tree.insertNode(9);
    tree.insertNode(11);
    tree.printTree();

    tree.searchKey(9);
    tree.searchKey(99);

    return 0;
}