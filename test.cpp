//
// Created by Евгений Дмитриев on 06.06.2021.
//

#include <iostream>
#include "DiscreteMath/CompressionAlgos/HuffmanTree.h"
#include "DiscreteMath/CompressionAlgos/LZMA.h"
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    LZMA lzma;
    string s; cin >> s;
    vector<char> word;
    for(auto u : s) {
        word.push_back(u);
    }
    lzma.deltaEncode(word, word.size());
    return 0;
}