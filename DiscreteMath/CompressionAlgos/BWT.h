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
    string encodeBWT(string s) {
        s += '$';
        vector<string> strings;
        for(int i = 0; i < s.length(); ++i) {
            string temp;
            for(int j = 0; j < s.length(); ++j) {
                temp += s[(i + j) % s.length()];
            }
            strings.push_back(temp);
        }
        sort(strings.begin(), string.end());
        string ans;
        for(auto u : strings) {
            ans += u.back();
        }
        return ans;
    }
    string encodeDeprecatedBWT(string s) { // Slow variant
        // We can make it fast. If we look at i and j places. Changes repeated, then we can sort only one time. not s.length()
        // But i'm lazy to do that
        int from = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '$') {
                from = i;
                break;
            }
        }
        vector<string> vc(s.length());
        for(int i = 0; i < s.length(); ++i) {
            for(int j = 0; j < s.length(); ++j) {
                vc = s[j] + vc
            }
            sort(vc.begin(), vc.end());
        }
        return vc[from];
    }
private:

};

#endif //TRAIN_BWT_H
