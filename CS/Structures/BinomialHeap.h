//
// Created by Евгений Дмитриев on 09.06.2021.
//

#ifndef TRAIN_BINOMIALHEAP_H
#define TRAIN_BINOMIALHEAP_H

#include <iostream>

using namespace std;

struct node {

    int key;
    int grade;
    node *parent, *child, *next;
};

class BinomialHeap {
public:

    BinomialHeap() {
        head = nullptr;
    }

    void printHeap() {
        this->printTree(this->head);
    }

    void insert(int x) {
        if (head) {
            node *newNode = CreateNode(x);
            head = union_tree(head, newNode);
        } else {

            head = (CreateNode(x));
        }
    }

    bool search(int x) {
        node *currPtr = head;
        while (currPtr != nullptr) {
            queue<node *> q;
            q.push(currPtr);
            while (!q.empty()) {
                node *p = q.front();
                q.pop();
                if (p->key == x) {

                    return true;
                }
                if (p->child != nullptr) {
                    node *tempPtr = p->child;
                    while (tempPtr != nullptr) {
                        q.push(tempPtr);
                        tempPtr = tempPtr->next;
                    }
                }
            }
            currPtr = currPtr->next;
        }

        return false;
    }

    void join(BinomialHeap *h1) {
        union_tree(head, h1->head);
        head = nullptr;
    }

    node *getMin() {
        node *ptr = this->head;

        if (ptr == nullptr) return nullptr;
        node *minNode = ptr;
        while (ptr->next) {
            ptr = ptr->next;
            if (minNode->key > ptr->key) {
                minNode = ptr;
            }
        }
        return minNode;
    }

    node *B_head() {
        return head;
    }
private:
    node *head;

    node *CreateNode(int x) {
        node *n = new node();
        n->key = x;
        n->parent = nullptr;
        n->child = nullptr;
        n->next = nullptr;
        n->grade = 0;
        return n;
    }

    void link_tree(node * tree_1, node * tree_2) {
        tree_1->parent = tree_2;
        tree_1->next = tree_2->child;
        tree_2->child = tree_1;
        tree_2->grade = tree_1->grade + 1;
    }

    node *merge_tree(node * Heap_1, node * Heap_2) {
        node *head;
        node *It_heap1 = Heap_1;
        node *It_heap2 = Heap_2;
        node *tail;

        if (It_heap1->grade <= It_heap2->grade) {
            head = It_heap1;
            It_heap1 = Heap_1->next;
        } else {
            head = It_heap2;
            It_heap2 = Heap_2->next;
        }
        tail = head;

        while (It_heap1 != nullptr && It_heap2 != nullptr) {

            if (It_heap1->grade <= It_heap2->grade) {
                tail->next = It_heap1;
                It_heap1 = It_heap1->next;
            } else {
                tail->next = It_heap2;
                It_heap2 = It_heap2->next;
            }

            tail = tail->next;
        }

        if (It_heap1 != nullptr) {
            tail->next = It_heap1;
        } else tail->next = It_heap2;

        return head;
    }

    node *union_tree(node * Heap_1, node * Heap_2) {
        node *heapList = merge_tree(Heap_1, Heap_2);
        if (heapList != nullptr) {

            node *aux = heapList;
            node *next_aux = aux->next;
            node *prev_aux = nullptr;

            while (next_aux != nullptr) {
                if (aux->grade != next_aux->grade || (next_aux->next != nullptr && next_aux->next->grade == aux->grade)) {
                    prev_aux = aux;
                    aux = next_aux;
                } else {
                    if (aux->key <= next_aux->key) {
                        aux->next = next_aux->next;
                        link_tree(next_aux, aux);

                    } else {
                        if (prev_aux == nullptr) heapList = next_aux;
                        else prev_aux->next = next_aux;
                        link_tree(aux, next_aux);
                        aux = next_aux;
                    }
                }
                next_aux = aux->next;
            }
        }
        return heapList;
    }

    void printTree(node * h) {
        while (h) {
            std::cout << std::endl
                      << "|key:" << h->key
                      << ", grade:" << h->grade;
            if (h->parent != nullptr) {
                std::cout << ", parent:" << h->parent->key;
            }
            if (h->child != nullptr) {
                std::cout << ", child:" << h->child->key;
            }
            if (h->next != nullptr) {
                std::cout << ", next:" << h->next->key;
            }
            std::cout << "|";
            this->printTree(h->child);
            h = h->next;
        }
    }
};

#endif //TRAIN_BINOMIALHEAP_H
