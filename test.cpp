#include "main.h"
#include <sstream>
#include <gtest/gtest.h>

TEST(PracticeTest, Test){
    std::string input("abcdef");
    std::ostringstream oss;
    oss << findBiggestSubstr(input);
    ASSERT_EQ("ab", oss.str());
}

TEST(PracticeTest, Test2){
    std::string input("aaaaaa");
    std::ostringstream oss;
    oss << findBiggestSubstr(input);
    ASSERT_EQ("aaaaaa", oss.str());
}

TEST(PracticeTest, Test3){
    std::string input("a");
    std::ostringstream oss;
    oss << findBiggestSubstr(input);
    ASSERT_EQ("a", oss.str());
}

TEST(PracticeTest, Test4){
    std::string input("aabbcddee");
    std::ostringstream oss;
    oss << findBiggestSubstr(input);
    ASSERT_EQ("aabb", oss.str());
}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}