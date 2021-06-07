//
// Created by Евгений Дмитриев on 07.06.2021.
//

#ifndef TRAIN_LZ78_H
#define TRAIN_LZ78_H
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
    int pos;
    char next;
};


class LZ78 {
public:
    vector<Node> encodeLZ78(string s) {
        string buffer = "";
        map<string, int> dict;
        vector<Node> ans;
        for(int i = 0; i< s.size(); ++i) {
            if(dict[buffer + s[i]] != 0) {
                buffer += s[i];
            }
            else {
                Node temp;
                temp.pos = dict[buffer];
                temp.next = s[i];
                ans.push_back(temp);
                dict[buffer + s[i]] = dict.size() + 1;
                buffer  = "";
            }
        }
        if(!buffer.empty()) {
            auto last_ch = buffer.back();
            buffer.pop_back();
            Node temp;
            temp.pos = dict[buffer];
            temp.next = last_ch;
            ans.push_back(temp);
        }
        return ans;
    }

    string decodeLZ78(vector<Node> encoded) {
        vector<string> dict; dict.push_back("");
        string ans = "";
        for(auto node : encoded) {
            auto word = dict[node.pos] + node.next;
            ans += word;
            dict.push_back(word);
        }
        return ans;
    }
private:

};


#endif //TRAIN_LZ78_H
