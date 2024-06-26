#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
        unsigned long long w[5] = {0};
        size_t idx = 4;
        
        for(int i = (k.size() - 1); i >= 0; i-=6){
            unsigned long long factor = 1;
            for(int j = i; j > i - 6 && j >= 0; j --){
                int c = letterDigitToNumber(k[j]);
                w[idx] += c * factor;
                factor *= 36;
            }
            idx --;
        }
        unsigned long long h = 0;
        for(int i = 0; i < 5; i ++)
            h += rValues[i] * w[i];
        
        return h;
    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
        if(letter >= 'A' && letter <= 'Z'){
            letter += 32;
        }

        return (letter >= 'a' && letter <= 'z') ? letter - 97 : letter - 22;
    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
