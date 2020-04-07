#include "main.h"
#include <iostream>

int main(int argc, char* argv[]){
    std::string input(argv[1]);
    std::cout << findBiggestSubstr(input) << std::endl;
    return 0;
}