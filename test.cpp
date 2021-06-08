//
// Created by Евгений Дмитриев on 06.06.2021.
//

#include <iostream>
//#include "DiscreteMath/CompressionAlgos/HuffmanTree.h"
//#include "DiscreteMath/CompressionAlgos/LZMA.h"
//#include "CS/Algos/Sort/RadixSort.h"
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


struct Node {
    char letter;
    int last;
    int current;
};


int main() {
    string s; cin >> s;
    vector<Node> word;
    int i = 0;
    for(auto &u : s) {
        Node temp;
        temp.letter = u;
        temp.last = i;
        word.push_back(temp);
        ++i;
    }
    auto comp = [](const Node a, const Node b) {
        return a.letter < b.letter;
    };
    sort(word.begin(), word.end(), comp);
    i = 0;
    for(auto &u : word) {
        u.current = i++;
    }
    for(auto u : word) {
        cout << u.letter << " " << u.current << " " << u.last << endl;
    }
    cout << "================" << endl;
    auto comp_2 = [](const Node a, const Node b) {
        return a.last < b.last;
    };
    sort(word.begin(), word.end(), comp_2);
    for(auto u : word) {
        cout << u.letter << " " << u.last << " " << u.current << endl;
    }
    return 0;
}