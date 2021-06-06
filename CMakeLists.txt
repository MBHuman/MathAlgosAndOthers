cmake_minimum_required(VERSION 3.19)
project(Discrete_algo)

set(CMAKE_CXX_STANDARD 20)
set(ALL_SRCS CACHE INTERNAL "mydescription" force)
set_directory_properties(DiscreteMath/CompressionAlgos/HuffmanAlgo)

add_executable(Discrete_algo main.cpp DiscreteMath/CompressionAlgos/HuffmanAlgo/Huffman.cpp)