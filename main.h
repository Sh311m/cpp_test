#include <string>
#include <algorithm>
#include <unordered_map>

std::string findBiggestSubstr(std::string &input){
    std::unordered_map <char,int32_t> container; 
    uint32_t max = 0, bstart = 0, start = 0, cnt = 0;
    std::for_each(input.begin(), input.end(), [&](char &n){
        auto search = container.find(n);
        container[n] = (search != container.end()) ? container[n] + 1 : 1;

        if(container.size() > 2){
            bstart = ((cnt - start) > max)? start : bstart;
            max = std::max(max, cnt-start);
            while(container.size() > 2){
                char t = input.at(start);
                uint32_t count = container[t];
                if(count > 1){
                    container[t] = count - 1;
                }else{
                    container.erase(t);
                }
                start++;
            }
        }
        cnt++;
    });

    bstart = ((cnt - start) > max)? start : bstart;
    max = std::max(max, (uint32_t)(input.length() - start));
    return input.substr(bstart, max);
}