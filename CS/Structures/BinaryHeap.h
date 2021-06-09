//
// Created by Евгений Дмитриев on 09.06.2021.
//

#ifndef TRAIN_BINARYHEAP_H
#define TRAIN_BINARYHEAP_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class BinaryHeap {
public:

    BinaryHeap() {
        heapSize = 0;
        a.resize(5);
    }

    void siftDown(int i) {
        while(2 * i + 1 < heapSize) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            auto j = left;
            if(right < heapSize and a[right] < a[left])
                j = right;
            if (a[i] <= a[j])
                break;
            swap(a[i], a[j]);
            i = j;
        }
    }
    void siftUp(int i) {
        while(a[i] < a[(i - 1) / 2]) {
            swap(a[i], a[(i -  1) / 2]);
            i = (i - 1) / 2;
        }
    }
    int extractMin() {
        if(a.size() > heapSize * 3) {
            vector<T> b(heapSize * 2);
            for(int i = 0; i < heapSize; ++i) {
                b[i] = a[i];
            }
            a = b;
        }
        int min = a[0];
        a[0] = a[heapSize - 1];
        heapSize = heapSize - 1;
        siftDown(0);
        return min;
    }
    void insert(T key) {
        if(heapSize == a.size()) {
            vector<T> b(a.size() * 2);
            for(int i = 0; i < a.size(); ++i) {
                b[i] = a[i];
            }
            a = b;
        }
        heapSize = heapSize + 1;
        a[heapSize - 1] = key;
        siftUp(heapSize - 1);
    }
private:
    vector<T> a;
    int heapSize;
};

#endif //TRAIN_BINARYHEAP_H
