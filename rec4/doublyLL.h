struct Node {
    int key;
    Node* prev;
    Node* next;
};

class doublyLL {
    private:
        Node* createNode(int,Node*,Node*);
        Node* head = nullptr;
        Node* tail = nullptr;
    public:
        bool insertNodeAtEnd(int);
        bool deleteNode(int);
        void printList();
        doublyLL();
        doublyLL(int);
        ~doublyLL(); //destructor
};