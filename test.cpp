//
// Created by Евгений Дмитриев on 06.06.2021.
//

#include <iostream>
//#include "DiscreteMath/CompressionAlgos/HuffmanTree.h"
//#include "DiscreteMath/CompressionAlgos/LZMA.h"
//#include "CS/Algos/Sort/RadixSort.h"
#include "CS/Structures/BinaryHeap.h"
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    BinaryHeap<int> binaryHeap;
    binaryHeap.insert(1);
    binaryHeap.insert(-4);
    binaryHeap.insert(-4);
    binaryHeap.insert(5);
    binaryHeap.insert(20);
    binaryHeap.insert(12);
    binaryHeap.insert(8);
    binaryHeap.insert(-20);
    cout << binaryHeap.extractMin() << endl;
    return 0;
}