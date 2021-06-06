//
// Created by zenka on 05.06.2021.
//

#ifndef DISCRETE_ALGO_HUFFMAN_H
#define DISCRETE_ALGO_HUFFMAN_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;


struct Node {
    Node * left = nullptr;
    Node * right = nullptr;
    pair<int, char> value;
};

class Huffman {
public:
    map<char, string> getCodes(string s);
    void encodeString(Node *s, string m);

    Node * merge(Node *f1, Node *f2);
private:
    vector<Node> tree;
    map<char, string> codes;
};


#endif //DISCRETE_ALGO_HUFFMAN_H
