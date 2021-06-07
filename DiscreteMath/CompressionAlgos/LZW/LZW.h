//
// Created by Евгений Дмитриев on 07.06.2021.
//

#ifndef TRAIN_LZW_H
#define TRAIN_LZW_H
#include "../HuffmanAlgo/HuffmanTree.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;


class LZW {
public:
    void encode(string s) {

        string f = reinterpret_cast<basic_string<char> &&>(s[0]);

    }
    bool inTable(map<string, int> ht, string a) {
        return ht.find(a) != ht.end();
    }
private:
    map<string, int> table;
};


#endif //TRAIN_LZW_H
