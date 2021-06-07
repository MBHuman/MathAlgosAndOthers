//
// Created by Евгений Дмитриев on 06.06.2021.
//

#ifndef TRAIN_HUFFMANALGO_H
#define TRAIN_HUFFMANALGO_H

#include <vector>
#include <map>

using namespace std;

class HuffmanAlgo {
public:
    pair<vector<int>, int> HuffmanCoding(vector<int> a) {
        int n = a.size();
        vector<int> b(n);
        int i = 0, j = 0, ans = 0;
        for (int k = 0; k < n; ++k) {
            b[k] = 91992929;
        }

        for(int k = 0; k < n - 1; ++k) {
            if(a[i] + a[i + 1] <= a[i] + b[j] and a[i] + a[i + 1] < b[j] + b[j + 1]) {
                b[k] = a[i] + a[i + 1];
                ans += b[k];
                i+=2;
                continue;
            }
            if(a[i] + b[j] <= a[i] + a[i + 1] and a[i] + b[j] <= b[j] + b[j + 1]) {
                b[k] = a[i] + b[j];
                ans += b[k];
                ++i;
                ++j;
                continue;
            }
            if(b[j] + b[j + 1] <= a[i] + a[j + 1] and b[j] + b[j + 1] <= a[i] + b[j]) {
                b[k] = b[j] + b[j + 1];
                ans += b[k];
                j+=2;
                continue;
            }
        }
        return {b, ans};
    }

private:
    int INF = 9919299292222;
};


#endif //TRAIN_HUFFMANALGO_H
