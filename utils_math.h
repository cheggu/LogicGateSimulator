#include <iostream>
#include <random>
#include <string>

std::string genUID() {
    // Seed the random number generator with a random seed
    std::random_device rd;
    std::mt19937 gen(rd());

    // Set up a uniform distribution to generate random characters
    std::uniform_int_distribution<int> dist('a', 'z');

    // Create a string of 16 random characters
    std::string str;
    for (int i = 0; i < 16; i++) {
        str += static_cast<char>(dist(gen));
    }

    //std::cout << str << std::endl;

    return str;
}