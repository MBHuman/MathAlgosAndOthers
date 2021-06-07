//
// Created by Евгений Дмитриев on 07.06.2021.
//

#ifndef TRAIN_LZSS_H
#define TRAIN_LZSS_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct output
{
    bool flag = true;
    short length = 0;
    std::size_t offset = 0;
    std::string charNotFound = "fasd";

} coder;

class LZSS {

    static const short dictLength = 8;
    static const short bufLength = 8;
public:
    explicit LZSS(std::string s, short dl = dictLength, short bl = bufLength) {
        this->input = s;
        this->dictionaryLength = dl;
        this->bufferLength = bl;
        dictionary.assign(dl, s[0]);
    }
    explicit LZSS(short dl = dictLength, short bl = bufLength) {
        this->dictionaryLength = dl;
        this->bufferLength = bl;
    }
    void changeParameters(short dl, short bl) {
        this->dictionaryLength = dl;
        this->bufferLength = bl;
        this->dictionary.assign(dl, this->input[0]);
    }
    void compress() {
        std::cout << "Compression begins..." << std::endl;
        std::string chain = dictionary + input;

        for (int i = 0; i < input.size();) { // i will be incremented by the value of length of the last encoded
            //dictionary.resize(chain.length());

            // update the dictionary
            dictionary = chain.substr(i, dictionaryLength);

            //initialize buffer that will be later used to find LCS with dictionary (default length of buffer=4)
            std::string buffer = input.substr(i, bufferLength);

            // find the longest common subsequence, until there is data in the buffer
            // if nothing is found, stding::find() will return string::npos <- termination condition
            while (dictionary.find(buffer) == std::string::npos && buffer.length() > 1)
                buffer.pop_back();

            // if nothing found: match is less than minimum allowable match length
            if (dictionary.find(buffer) == std::string::npos) { // storing the uncoded flag and the first uncoded symbol
                coder.flag = true;								// flag
                coder.length = buffer.length();					// buffer will be moved by one position
                coder.offset = dictionary.find(buffer);			//
                coder.charNotFound = buffer;					// in dictionary there is no sequence starting with letter that is left in the buffer
                this->encoded.push_back(coder);
            }
            else   // match found: storing encoded flag, the offset and length
            {
                coder.flag = false;
                coder.offset = dictionary.find(buffer);			// find returns the position of the first character of the first match
                coder.length = buffer.length();					// length of the found LCS
                coder.charNotFound = "";
                this->encoded.push_back(coder);
            }

            i += buffer.length();								// updating the size of actually encoded string
        }
        this->showEncoded();

        this->decompress();
    }
private:
    short dictionaryLength;
    short bufferLength;
    std::string input;
    std::string dictionary;


    std::vector<output> encoded;

    void showEncoded() const {
        for (auto i : encoded)
        {
            if (!i.flag)
                std::cout << static_cast<int>(i.flag) << i.offset << i.length << std::endl;
            else
                std::cout << static_cast<int>(i.flag) << i.charNotFound << std::endl;

        }
    }
    void decompress() {
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Decompression begins..." << std::endl;
        std::string outputString{ "" };
        dictionary.assign(this->dictionaryLength, input[0]);
        std::string chain = dictionary;

        for (auto i : encoded) {
            if (i.flag == true) {						// printing a pair (encoded flag, first unencoded symbol)
                outputString += i.charNotFound;			// there was no sequence that starts with i.charNotFound in the dictionary
                chain += i.charNotFound;
            }
            else
            {
                outputString += chain.substr(i.offset, i.length);	// print triple (encoded flag, offset(indeks początku podciągu), length)
                chain += chain.substr(i.offset, i.length);
            }
            chain.erase(0, i.length);  // update the chain
        }

        std::cout << "###############################" << std::endl;

        std::cout << "Decoded string: " << std::endl;
        std::cout << outputString << std::endl;
    }
    std::string readTextFile() {
        std::string inFileName = "text.txt";
        std::ifstream inFile;
        inFile.open(inFileName);

        std::string line;

        if (inFile.is_open()) {

            while (!inFile.eof()) {
                getline(inFile, line);
            }
            std::cout << line << std::endl;
            inFile.close();
        }
        else {
            std::cout << "Cannot open the file: " << inFileName << ". Setting the input string to default" << std::endl;
            line = "aabbcabbcabd";
        }

        return line;
    }
};

#endif //TRAIN_LZSS_H
