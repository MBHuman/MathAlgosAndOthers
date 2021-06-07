//
// Created by Евгений Дмитриев on 06.06.2021.
//

#include <iostream>
//#include "DiscreteMath/CompressionAlgos/HuffmanAlgoO(n)/HuffmanAlgo.h"
//#include "CS/Algos/Sort/radix_sort/RadixSort.h"
#include <map>
#include <algorithm>
#include <vector>

using namespace std;




struct Node {
    Node * left;
    Node * right;
    int value;
};

class VectorList {
public:
    VectorList() {
        list.reserve(10);
    }
    void insert(int value) {
        if(last == list.size()) {
            vector<int> new_list;
            new_list.reserve(list.size() * 2);
            for(int i = 0; i< list.size(); ++i) {
                new_list[i] = list[i];
            }
            list = new_list;
        }
        list[last] = value;
        last++;
    }
private:
    vector<int> list;
    int last = 0;
};


int main() {


    return 0;
}