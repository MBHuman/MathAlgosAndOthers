//
// Created by Евгений Дмитриев on 08.06.2021.
//

#ifndef TRAIN_BWT_H
#define TRAIN_BWT_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Burrows-Wheeler-transform

struct Node {
    char letter;
    int last;
    int current;
};

class BWT {
public:
    vector<int> reverseBWT(int N, int M, int k, string s) {
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
        auto comp = [](const Node a, const Node b) {
            return a.last < b.last;
        };
        sort(word.begin(), word.end(), comp);

    }
private:

};

#endif //TRAIN_BWT_H
