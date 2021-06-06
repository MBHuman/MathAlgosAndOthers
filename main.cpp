//
// Created by zenka on 05.06.2021.
//

#include <iostream>
#include "DiscreteMath/CompressionAlgos/HuffmanAlgo/Huffman.h"


using namespace std;

int main() {
    Huffman solve;
    string s; cout << "Введите код" << endl;
    cin >> s;
    auto table = solve.getCodes(s);
    for(auto u : table) {
        cout << u.first << " " << u.second << endl;
    }
    return 0;
}