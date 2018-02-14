#include <iostream>
#include "./doublyLL.cpp"

using namespace std;

int main() {
    doublyLL list;

    list.insertNodeAtEnd(4);
    list.insertNodeAtEnd(1);
    list.insertNodeAtEnd(4);
    list.insertNodeAtEnd(2);
    list.insertNodeAtEnd(4);
    list.insertNodeAtEnd(3);
   
    list.insertNodeAtEnd(4);
    list.insertNodeAtEnd(5);
    list.insertNodeAtEnd(4);
    list.insertNodeAtEnd(6);
    list.insertNodeAtEnd(4);
    
    list.insertNodeAtEnd(7);
    list.insertNodeAtEnd(4);
    list.insertNodeAtEnd(8);
    list.insertNodeAtEnd(4);
    list.insertNodeAtEnd(9);
    
    list.insertNodeAtEnd(4);
    list.insertNodeAtEnd(10);
    list.insertNodeAtEnd(4);
    list.insertNodeAtEnd(11);
    list.insertNodeAtEnd(4);
    
    cout << "Initial List:" << endl;
    list.printList();

    list.deleteNode(4);

    cout << endl;
    cout << "Updated List:" << endl;
    list.printList();
}