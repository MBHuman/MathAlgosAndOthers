//
// Created by zenka on 05.06.2021.
//

#include <iostream>

using namespace std;

class LinkedList {
    struct Node {
        int value;
        Node * next;
        Node * prev;
    };

public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node * next = head;
        while(next) {
            Node * delMe = next;
            next = next->next;
            delete delMe;
        }
    }

    void addElem(int value) {
        Node * temp = new Node();
        temp->value = value;
        temp->next = head;
        head = temp;
    }

    int popElem() {
        Node * temp = head;
        int ret = temp->value;

        head = head->next;
        delete temp;
        return ret;
    }

    bool full() {
        return head->next;
    }

private:
    Node *head;
};

int main() {
    LinkedList list;
    list.addElem(23);
    list.addElem(12);
    while(list.full()) {
        cout << list.popElem() << endl;
    }

    return 0;
}