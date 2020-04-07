#include "main.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size){
    if (0 == Size)
        return 0;
    std::string input((char*)Data,Size); 
    std::string result = findBiggestSubstr(input);
    return !result.empty();
}