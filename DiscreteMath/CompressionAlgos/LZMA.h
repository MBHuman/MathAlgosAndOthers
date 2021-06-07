//
// Created by Евгений Дмитриев on 07.06.2021.
//

#ifndef TRAIN_LZMA_H
#define TRAIN_LZMA_H
#include <vector>
#include "LZ77.h"

class LZMA {
public:

    vector<NodeLZ77> encodeLZMA(string s) {
        LZ77 lz77;
        vector<char> codes;
        for(auto u: s)
            codes.push_back(u);
        deltaEncode(codes, codes.size());

        // need to change LZ77 code for vector<char> codes
        string line="";
        for(auto u : codes)
            line += u;
        auto code = lz77.encodeLZ77(line);
        return code;
    }

    string decodeLZMA(vector<NodeLZ77> code) {
        LZ77 lz77;
        string encode = lz77.decodeLZ77(code);
        vector<char> codes;
        for(auto u : encode)
            codes.push_back(u);
        deltaEncode(codes, codes.size());
        string ans = "";
        for(auto u : codes)
            ans += u;
        return ans;
    }
    void deltaEncode(vector<char> bp, int n) {
        char last = 0;
        for(int i = 0; i < n; ++i) {
            char tmp = bp[i];
            bp[i] -= last;
            last = tmp;
        }
    }
    void deltaDecode(vector<char> bp, int n) {
        char last = 0;
        for(int i = 0; i < n - 1; ++i) {
            bp[i] += last;
            last = bp[i];
        }
    }

};

#endif //TRAIN_LZMA_H
