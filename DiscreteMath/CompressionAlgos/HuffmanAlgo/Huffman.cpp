//
// Created by zenka on 05.06.2021.
//

#include "Huffman.h"
#include <iostream>

map<char, string> Huffman::getCodes(string s) {
    map<char, int> W;
    for(char u: s) {
        W[u]++;
    }
    vector<Node> nodes;
    for(auto u : W) {
        Node temp;
        temp.value = {u.second, u.first};
        nodes.push_back(temp);
    }
    auto symbol_comparator = [](const Node a, const Node b) {
        return a->value.first < b->value.first;
    };
    sort(nodes.begin(), nodes.end(), symbol_comparator);
    while(nodes.size() > 1) {
        Node temp = merge(nodes[nodes.size() - 1], nodes[nodes.size() - 2]);
        nodes.pop_back();
        nodes.pop_back();
        nodes.push_back(temp);
        sort(nodes.begin(), nodes.end(), symbol_comparator);
    }
    Node *tree= nodes[0];
    encodeString(tree, "");
    return codes;
}

void Huffman::encodeString(Node *s, string m) {
    if(s->left != nullptr) {
        encodeString(s->left, m + "0");
    }
    if(s->right != nullptr) {
        encodeString(s->right, m + "1");
    }
    if(s->right == nullptr and s->left == nullptr) {
        codes[s->value.second] = m;
    }
}

Node * Huffman::merge(Node *f1, Node *f2) { 
    Node *f;
    f->left = f1;
    f->right = f2;
    f->value = (f1->value.first + f2->value.first, f1->value.second + f2->value.second);
    return f;
}