#include <iostream>
#include <string>
#include "md5.h"

int main() {
    std::string input;
    std::cout << "plz enter something: ";
    std::getline(std::cin, input);

    std::string hash = compute_md5(input);
    std::cout << "MD5 Hash is: " << hash << std::endl;

    return 0;
}
