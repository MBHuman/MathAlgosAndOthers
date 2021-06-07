//
// Created by Евгений Дмитриев on 07.06.2021.
//

#ifndef TRAIN_LZ77_H
#define TRAIN_LZ77_H
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct NodeLZ77 {
    int offset;
    int length;
    char next;
};


class LZ77 {
public:
    vector<NodeLZ77> encodeLZ77(string s) {
        vector<NodeLZ77> ans;
        encoding = s;
        current_pos = 0;
        int pos = 0;
        while(pos < s.size()) {
            auto temp = findMatching(buffer, pos);
            int offset = temp[0], length = temp[1];
            shiftBuffer(length + 1);
            pos += length;
            NodeLZ77 temp2;
            temp2.offset = offset;
            temp2.length = length;
            temp2.next = s[pos];
            ans.push_back(temp2);
        }
        return ans;
    }
    string decodeLZ77(vector<NodeLZ77> encoded) {
        string ans = "";
        for(auto node : encoded) {
            if(node.length > 0) {
                auto start = ans.length() - node.offset;
                for(int i = 0; i < node.length - 1; ++i) {
                    ans += ans[start + i];
                }
            }
            ans += node.next;
        }
        return ans;
    }

private:
    vector<int> findMatching(vector<char> buffer, int pos) {
        int offset = 0, length = 0;
        int i = 0;
        if(buffer[0] == encoding[pos]) {
            offset = pos - buffer.size();
            while(buffer[i] == encoding[pos + i]) {
                ++length;
                ++i;
            }
        }
        vector<int> ans = {offset, length};
        return ans;
    }
    void shiftBuffer(int size) {
        vector<int> new_buffer(buffer.size());
        int j = 0;
        for(int i = current_pos + size; i < current_pos +buffer.size(); ++i) {
            new_buffer[j] = encoding[i];
            ++j;
        }
        current_pos = current_pos + size;
    }

    vector<char> buffer;
    string encoding;
    int current_pos;
};


#endif //TRAIN_LZ77_H
