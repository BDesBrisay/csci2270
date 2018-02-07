#include <iostream>

using namespace std;

struct node {
    int value;
    node* next;
};

class list {
    public:
        node *head, *tail;
        int index;

        list() {
            head = NULL;
            tail = NULL;
            add(1);
            add(2);
            add(3);
            add(5);
            add(7);
            add(9);
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

        void addEven(int n) {
            node* temp = new node;
            node* place = head;
            temp->value = n;

            while (place != NULL) {
                if (!(place->value % 2)) {
                    temp->next = place->next;
                    place->next = temp;
                    break;
                } else {
                    place = place->next;
                }
            }
        }

        void print() {
            node *place = head;
            while ( place != NULL ) {
                cout << place->value << endl;
                place = place->next;
            }
        }
};

int main() {
    list a;

    a.print();

    cout << "New List: " << endl;

    a.addEven(1234);

    a.print();

    return 0;
}