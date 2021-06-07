cmake_minimum_required(VERSION 3.19)
project(Discrete_algo)
project(Test)
project(Train)


set(CMAKE_CXX_STANDARD 20)
set(ALL_SRCS CACHE INTERNAL "mydescription" force)
set_directory_properties(DiscreteMath/CompressionAlgos/HuffmanAlgo)


add_executable(Train main.cpp)
add_executable(Test test.cpp)
add_executable(Discrete_algo test.cpp DiscreteMath/CompressionAlgos/HuffmanAlgo/Node.h DiscreteMath/CompressionAlgos/HuffmanAlgo/HuffmanTree.h DiscreteMath/CompressionAlgos/Hu-Tucker/HuTucker.cpp DiscreteMath/CompressionAlgos/Hu-Tucker/HuTucker.h "DiscreteMath/CompressionAlgos/HuffmanAlgoO(n)/HuffmanAlgo.cpp" "DiscreteMath/CompressionAlgos/HuffmanAlgoO(n)/HuffmanAlgo.h" CS/Algos/Sort/radix_sort/RadixSort.cpp CS/Algos/Sort/radix_sort/RadixSort.h DiscreteMath/CompressionAlgos/LZ77/LZ77.cpp DiscreteMath/CompressionAlgos/LZ77/LZ77.h DiscreteMath/CompressionAlgos/LZ78/LZ78.cpp DiscreteMath/CompressionAlgos/LZ78/LZ78.h DiscreteMath/CompressionAlgos/LZW/LZW.cpp DiscreteMath/CompressionAlgos/LZW/LZW.h)