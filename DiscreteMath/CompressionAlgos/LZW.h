//
// Created by Евгений Дмитриев on 07.06.2021.
//

#ifndef TRAIN_LZW_H
#define TRAIN_LZW_H
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

class LZW {
public:
    /*
     *
     * How to use compress:
     * string s; cin >> s;
     * LZW lzw;
     * vector<int> compressed;
     * lzw.compress(s, std::back_inserter(compressed));
     */
    template<typename Iterator>
    Iterator compress(const string &uncompressed, Iterator result) {
        // Build the dictionary.
        int dictSize = 256;
        std::map<std::string,int> dictionary;
        for (int i = 0; i < 256; i++)
            dictionary[std::string(1, i)] = i;

        string w;
        for (std::string::const_iterator it = uncompressed.begin();
             it != uncompressed.end(); ++it) {
            char c = *it;
            string wc = w + c;
            if (dictionary.count(wc))
                w = wc;
            else {
                *result++ = dictionary[w];
                // Add wc to the dictionary. Assuming the size is 4096!!!
                if (dictionary.size()<4096)
                    dictionary[wc] = dictSize++;
                w = std::string(1, c);
            }
        }

        // Output the code for w.
        if (!w.empty())
            *result++ = dictionary[w];
        return result;
    }

    /*
     *
     * How to decompress
     * string nw;
     * nw = lzw.decompress(compressed.begin(), compressed.end());
     */

    template <typename Iterator>
    string decompress(Iterator begin, Iterator end) {
        // Build the dictionary.
        int dictSize = 256;
        std::map<int,std::string> dictionary;
        for (int i = 0; i < 256; i++)
            dictionary[i] = std::string(1, i);

        string w(1, *begin++);
        string result = w;
        string entry;
        for ( ; begin != end; begin++) {
            int k = *begin;
            if (dictionary.count(k))
                entry = dictionary[k];
            else if (k == dictSize)
                entry = w + w[0];
            else
                throw "Bad compressed k";

            result += entry;

            // Add w+entry[0] to the dictionary.
            if (dictionary.size()<4096)
                dictionary[dictSize++] = w + entry[0];

            w = entry;
        }
        return result;
    }
};


#endif //TRAIN_LZW_H
