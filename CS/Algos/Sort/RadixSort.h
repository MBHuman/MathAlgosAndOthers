//
// Created by Евгений Дмитриев on 06.06.2021.
//

#ifndef TRAIN_RADIXSORT_H
#define TRAIN_RADIXSORT_H

#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/time.h>
#include <vector>


template<typename T>
class RadixSort {
public:

    void insertion_sort(std::vector<T> &array, int offset, int end) {
        int x, y, temp;
        for (x=offset; x<end; ++x) {
            for (y=x; y>offset && array[y-1]>array[y]; y--) {
                temp = array[y];
                array[y] = array[y-1];
                array[y-1] = temp;
            }
        }
    }

    void radix_sort(std::vector<T> &array, int offset, int end, int shift) {
        int x, y, value, temp;
        int last[256] = { 0 }, pointer[256];

        for (x=offset; x<end; ++x) {
            ++last[(array[x] >> shift) & 0xFF];
        }

        last[0] += offset;
        pointer[0] = offset;
        for (x=1; x<256; ++x) {
            pointer[x] = last[x-1];
            last[x] += last[x-1];
        }

        for (x=0; x<256; ++x) {
            while (pointer[x] != last[x]) {
                value = array[pointer[x]];
                y = (value >> shift) & 0xFF;
                while (x != y) {
                    temp = array[pointer[y]];
                    array[pointer[y]++] = value;
                    value = temp;
                    y = (value >> shift) & 0xFF;
                }
                array[pointer[x]++] = value;
            }
        }

        if (shift > 0) {
            shift -= 8;
            for (x=0; x<256; ++x) {
                temp = x > 0 ? pointer[x] - pointer[x-1] : pointer[0] - offset;
                if (temp > 64) {
                    radix_sort(array, pointer[x] - temp, pointer[x], shift);
                } else if (temp > 1) {
                    // std::sort(array + (pointer[x] - temp), array + pointer[x]);
                    insertion_sort(array, pointer[x] - temp, pointer[x]);
                }
            }
        }
    }
};


#endif //TRAIN_RADIXSORT_H
