//
// Created by Евгений Дмитриев on 09.06.2021.
//

#ifndef TRAIN_FIBHEAP_H
#define TRAIN_FIBHEAP_H

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *parent;
    Node *child;
    Node *left;
    Node *right;
    int degree;
    boolean mark;
};


class FibHeap {
public:
    void buildHeap() {
        size = 0;
    }

    void insert(int x) {
        Node *newNode;
        newNode->key = x;
        if(size == 0) {
            min = newNode;
            min->left = newNode;
            min->right = newNode;
        }
        else {
            Node prevRight = min->right;
            min->right = newNode;
            newNode->left = min;
            newNode->right = prevRight;
            prevRight->left = newNode;
        }
        if(newNode->key < min->key)
            min = newNode;
        ++size;
    }

    void unionLists(Node * first, Node * second) {
        Node * L = first->left;
        Node * R = second->right;
        second->right = first;
        first->left = second;
        L->right = R;
        R->left = L;
    }

    void merge(FibHeap * that) {
        if(that->size = 0) {
            return;
        }
        if(size == 0) {
            min = that->min;
            size= that->size;
        }
        else {
            unionLists(min, that.min);
            size += that->size;
        }
        if min or (that->min and that->min < min) {
            min = that->min;
        }
    }

    int deleteMin() {
        Node * prevMin = min;
        unionLists(min, min->child);
        Node * L = min->left;
        Node * R = min->right;
        L->right = R;
        R->left = L;
        if(prevMin->right = prevMin) {
            return;
        }
        min = min->right;
        consolidate();
        --size;
        return prevMin->key;
    }

    void consolidate() {
        auto A = Node[];
        A[min->degree] = min;
        Node *current = min->right;
        while(A[current.degree] == current) {
            if (A[current.degree]) {
                A[current.degree] = current;
                current = current->right;
            }
            else {
                Node * conflict = A[current->degree];
                Node * addTo, * adding;
                if(conflict->key < current->key) {
                    addTo = conflict;
                    adding = current;
                }
                else {
                    addTo = current;
                    adding = conflict;
                }
                unionLists(addTo->child, adding);
                adding->parent = addTo;
                ++addTo->degree;
                current = addTo;
            }
            if(min->key > current->key) {
                min = current;
            }
        }
    }

    void decreaseKey(Node * x, int newValue) {
        if(newValue > x->parent->key) {
            x->key = newValue;
            return;
        }
        Node * parent = x->parent;
        cut(x);
        cascadingCut(parent);
    }

    void cut(Node * x) {
        Node * L = x->left;
        Node * R = x->right;
        R->left = L;
        L->right = R;
        --x->parent->degree;
        if(x->parent->child == x) {
            if(x->right == x) {
                x->parent->child;
            }
            else {
                x->parent->child = x->right;
            }
        }
        x->right = x;
        x->left = x;
        unionLists(min, x);
    }

    void cascadingCut(Node * x) {
        while(x->mark == true) {
            cut(x);
            x = x->parent;
        }
        x->mark = true;
    }

    void delete(Node* x) {
        decreaseKey(x, 100000000);
        deleteMin();
    }

    int getMin() {
        return min->key;
    }

private:
    int size;
    Node *min;
};

#endif //TRAIN_FIBHEAP_H
