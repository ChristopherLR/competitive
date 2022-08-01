#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::string> fizzBuzz(int n){
        std::vector<std::string> results;

        for (int i = 1; i <= n; i++){
            std::string result;
            if ( i % 3 == 0) result = "Fizz";
            if ( i % 5 == 0) result += "Buzz";
            if (result.empty()) result = std::to_string(i);
            results.push_back(result);
        }

        return results;
    };
};

TEST_CASE("T1") {
    Solution sol;
    std::vector<std::string> vs = {"1", "2", "Fizz"};
    REQUIRE(sol.fizzBuzz(3) == vs);
};

TEST_CASE("T2") {
    Solution sol;
    std::vector<std::string> vs = {"1", "2", "Fizz", "4", "Buzz"};
    REQUIRE(sol.fizzBuzz(5) == vs);
};
