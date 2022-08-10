#include <catch2/catch_test_macros.hpp>
#include <iostream>

class Solution {
  public:
    Runtime 4ms, Memory 6 MB
    int numberOfSteps(int num) {
        int count = 0;
        while (num > 0){
            if (num % 2 == 0) num /= 2;
            else num --;
            count ++;
        }
        return count;
    }
};

TEST_CASE("T1") {
    Solution sol;
    REQUIRE(sol.numberOfSteps(14) == 6);
};

TEST_CASE("T2") {
    Solution sol;
    REQUIRE(sol.numberOfSteps(8) == 4);
};

TEST_CASE("T3") {
    Solution sol;
    REQUIRE(sol.numberOfSteps(123) == 12);
};

TEST_CASE("T4") {
    Solution sol;
    REQUIRE(sol.numberOfSteps(4) == 3);
};