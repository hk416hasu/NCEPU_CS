#include <iostream>
#include "md5.h"

int main() {
    std::string input;
    std::cout << "Enter text to compute MD5: ";
    std::getline(std::cin, input);

    std::string hash = compute_md5(input);
    std::cout << "MD5 Hash: " << hash << std::endl;

    return 0;
}

