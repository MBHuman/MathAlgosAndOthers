//
// Created by Евгений Дмитриев on 11.06.2021.
//

#ifndef TRAIN_THICKTREE_H
#define TRAIN_THICKTREE_H

#include <iostream>
#include <vector>


using namespace std;

struct Node {
    int key;
    Node * parent;
    Node * left;
    Node * right;
    Node * lChild;
    int rank;
};

struct FatHeap {
    vector<int> rootCount[];
    int countViolation[];
    Node minPointer;
    int maxRank;
};

class ThickTree {
public:
    void fix(int i) {
        if(d[i] == b) {
            d[i] = 0;
            ++d[i + 1];
        }
        if(d[i + 1] == b - 1)
            L[i] = L[i + 1];
        else
            L[i] = i + 1;
    }

    void inc(int i) {
        fix(i);
        if(d[i] == b - 1 or d[i] == b - 2) {
            fix(L[i]);
        }
        ++d[i];
        fix(i);
    }

    void updateForwardPointer(int i) {
        if(rootCount[i + 1].value == 3 -1)
            rootCount[i].forwardPointer = rootCount[i + 1].forwardPointer;
        else
            rootCount[i].forwardPointer = i + 1;
    }
    void insertTree(int i, Node * p) {
        auto p1 = rootCount[i].listPointer;
        if(rootCount[i].Value != 0)
            p.right = p1;
        else
            p.right = NULL;
        p.left = NULL;
        rootCount[i].listPointer = p;
    }
    void deleteTree(int i, Node * p) {
        auto p1 = rootCount[i].listPointer;
        if(p1 == p)
            rootCount[i].listPointer = p.right;
        int j = 1;
        while(j <= rootCount[i].Value and p1.right != p) {
            ++j;
            p1 = p1.right;
        }
        p1.right = p.right;
    }
    Node * fastening(Node * p1, Node * p2, Node * p3) {
        Node * minP;
        if(p1->key <= p2->key and p1->key <= p3->key) {
            minP = p1;
            p1 = p2;
            p2 = p3;
        }
        if (p2->key <= p1->key and  p2->key <= p3.key) {
            minP = p2;
            p1 = p1;
            p2 =p3;
        }
        if(p3->key <= p1->key and p3->key <= p2->key) {
            minP = p3;
            p1 = p1;
            p2 = p2;
        }
        p1->right = p2;
        p1->left = nullptr;
        p1->parent = minP;
        p2->right = minP->lChild;
        p2->parent = minP;
        if(minP->lChild != nullptr)
            minP->lChild->left = p2;
        minP->lChild = p1;
        minP.rank = minP.rank + 1;
        minP.right = nullptr;
        minP.left = nullptr;
        return minP;
    }

    int getKey(Node p) {
        if(p == nullptr)
            min = 992193912312;
        else
            min = p.key;
        return min;
    }
    Node * minKeyNodeRoot(Node * p) {
        auto p1 = p;
        auto minP = p1;
        while(p1 != nullptr) {
            if(p1.key < minP.key) {
                minP = p1;
                p1 = p1.right;
            }
        }
        return minP;
    }
    void rmFixRootCount(int i) {
        if(maxRank == i) {
            maxRank = i + 1;
            rootCount[i + 1].Value = 0;
            countViolation[i + 1].Value = 0;
        }
        else {
            updateForwardPointer(i + 1);
        }
        rootCount[i].Value = 0;
        p1 = rootCount[i].listPointer;
        p2 = p1.right;
        p3 = p2.right;
        p = fastering(p1, p2, p3);
        rootCount[i].listPointer = nullptr;
        insertTree(i +1, p);
        rootCount[i + 1].Value = rootCount[i].Value + 1;
        updateForwardPointer(i);
        if(rootCount[i].Value == 3)
            fixRootCount(i);
    }
    void delete(int i, Node * p) {
        deleteTree(i, p);
        rootCount[i].Value = rootCount[i].Valu - 1;
    }

    Node * minKey() {
        Node * minP = nullptr;
        for(int i = 0; i < maxRank; ++i) {
            auto p1 = minKeyNodeRoot(rootCount[i].listPointer);
            if(getKey(p1) < getKey(minP))
                minP = p1;
        }
        return minP;
    }

    void deleteViolation(Node * h2) {
        for(int i = 0; i < h2.maxRank; ++i) {
            if(countViolation[i].Value == 2) {
                fixCountViolation(i);
            }
        }
        for(int i = 0; i < h2.maxRanl; ++i) {
            if(countViolation[i].Value == 1) {
                incCountViolation(i,
                                  searchBrother(countViolation[i].rmFirstviolation));
                fixCountViolation(i);
            }
        }
    }
private:

};

#endif //TRAIN_THICKTREE_H
