//
// Created by Евгений Дмитриев on 09.06.2021.
//

#ifndef TRAIN_THINHEAP_H
#define TRAIN_THINHEAP_H

#include <iostream>
#include <vector>

using namespace std;


struct Node {
    int key;
    int rank;
    Node * child;
    Node * right;
    Node * left;
};

class ThinHeap {

public:
    bool isThin(Node * x) {
        if (x->rank == 1) {
            return x->child == nullptr;
        } else {
            return x->child->rank + 1 != x->rank;
        }
    }

    void makeHeap() {
        ThinHeap **H = this;
        H->first = nullptr;
        H->last = nullptr;
        return H;
    }

    void insert(ThinHeap * H, Node * x) {
        if(H->first == nullptr) {
            H->first = x;
            H->last = x;
        }
        else {
            if(x->key < H->first->key) {
                x->right = H->first;
                H->first = x;
            }
            else {
                H->last->right = x;
                H->last = x;
            }
        }
    }

    Node * getMin(ThinHeap *H) {
        return H->first;
    }

    ThinHeap * merge(ThinHeap * H1, ThinHeap * H2) {
        if (H1->first == nullptr) {
            return H2;
        }
        else {
            if(H2->first == nullptr) {
                return H1;
            }
            else {
                if(H1->first->key < H2->first->key) {
                    H1->last->right = H2->first;
                    H1->last = H2->last;
                    return H1;
                }
                else {
                    H2->last->right = H1->last;
                    H2->last = H1->last;
                    return H2;
                }
            }
        }
    }

    Node * extractMin(ThinHeap * H) {
        Node *temp = H->first;
        H->first = H->first->right;
        if(H->first == nullptr) {
            H->last = nullptr;
        }
        Node *x = temp->first->child;
        while(x != nullptr) {
            if(isThin(x))
                x->rank = x->rank - 1;
            x->left = nullptr;
            auto next = x.right;
            insert(H, x);
            x = next;
        }
        max = -1;
        x = H->first;
        while(x != nullptr) {
            while(aux[x->rank] != nullptr) {
                auto next = x->right;
                if(aux[x->rank].key < x->key)
                    swap(aux[x->rank], x);
                aux[x->rank]->right = x->child;
                x->child->left = aux[x->rank];
                aux[x->rank]->left = x;
                x->child = aux[x.rank];
                aux[x->rank] = nullptr;
                x->rank = x->rank + 1;
            }
            aux[x->rank] = x;
            if (x->rank > max)
                max = x->rank;
            x=next;
        }
        H = makeHeap();
        int i = 0;
        while(i <= max) {
            insert(H, aux[i]);
            i = i + 1;
        }
        return tmp;
    }

    void delete(ThinHeap * H, Node * x) {
        decreaseKey(H, x, 10000223);
        extractMin();
    }
private:
    Node * first;
    Node * last;
};

#endif //TRAIN_THINHEAP_H
