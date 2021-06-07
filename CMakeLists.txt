cmake_minimum_required(VERSION 3.19)
project(Discrete_algo)
project(Test)
project(Train)


set(CMAKE_CXX_STANDARD 20)
set(ALL_SRCS CACHE INTERNAL "mydescription" force)
set_directory_properties(DiscreteMath/CompressionAlgos/HuffmanAlgo)


add_executable(Train main.cpp)
add_executable(Test test.cpp)
add_executable(Discrete_algo test.cpp DiscreteMath/CompressionAlgos/HuffmanTree.h DiscreteMath/CompressionAlgos/HuTucker.h "DiscreteMath/CompressionAlgos/HuffmanAlgoO(n).h" CS/Algos/Sort/RadixSort.h DiscreteMath/CompressionAlgos/LZ77.h DiscreteMath/CompressionAlgos/LZ78.h DiscreteMath/CompressionAlgos/LZW.h DiscreteMath/CompressionAlgos/LZSS.h DiscreteMath/CompressionAlgos/LZMA.h)