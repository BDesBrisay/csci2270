#include <iostream>

using namespace std;

struct node {
    int value;
    node* next;
};

class list {
    private:
        node *head, *tail;

    public: 
        list() {
            head = NULL;
            tail = NULL;
        }

        void add(int n) {
            node* temp = new node; 
            temp->value = n;
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = tail->next;
            }
        }

        void print() {
            node *place = head;
            while ( place != NULL ) {
                cout << place->value << endl;;
                place = place->next;
            }
        }
};

int main() {
    list a;
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);
    a.add(6);

    a.print();

    return 0;
}