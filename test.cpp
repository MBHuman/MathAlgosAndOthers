//
// Created by Евгений Дмитриев on 06.06.2021.
//

#include <iostream>
#include "DiscreteMath/CompressionAlgos/HuffmanTree.h"
#include "DiscreteMath/CompressionAlgos/LZW.h"
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    string s; cin >> s;
    LZW lzw;
    vector<int> compressed;
    lzw.compress(s, std::back_inserter(compressed));
    for(auto u : compressed) {
        cout << u << endl;
    }
    string nw;
    nw = lzw.decompress(compressed.begin(), compressed.end());
    cout << nw << endl;
    return 0;
}