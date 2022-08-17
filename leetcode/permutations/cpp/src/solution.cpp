#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

std::ostream &operator<<(std::ostream &os, std::vector<int> &vec) {
    std::string out = "";
    std::cout << "test" << std::endl;
    for (auto elem : vec)
        out += std::to_string(elem) + " ";
    
    return os << out;
};

// Pretty Poor Solution
// A better one here would be to switch vector indices inplace and then push them onto the results
// https://leetcode.com/submissions/detail/776032062/
class Solution {
  public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        if (nums.size() == 0)
            return std::vector<std::vector<int>>();
        if (nums.size() == 1)
            return std::vector<std::vector<int>>({{nums}});

        std::vector<std::vector<int>> outMat;

        for (int i = 0; i < nums.size(); i++) {
            auto pivot = nums[i];
            auto current = nums.begin() + i;
            auto nit = nums.begin();

            std::vector<int> remainder;
            for (;nit != nums.end(); nit++)
                if (nit != current)
                    remainder.push_back(*nit);
            
            for (auto p : permute(remainder)){
                p.insert(p.begin(), pivot);
                outMat.push_back(p);
            }
        }

        return outMat;
    }
};

typedef std::vector<std::vector<int>> matrix;

// This one is very fast (but also kinda cheating)
// https://leetcode.com/submissions/detail/776037328/
class Solution2 {
  public:
    matrix permute(std::vector<int> &nums) {
        matrix results;
        std::sort(nums.begin(), nums.end());
        do {
            results.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));

        return results;
    }
};


typedef std::vector<std::vector<int>> matrix;

matrix generatePermutations(std::vector<int> &nums) {
    matrix results;
    std::sort(nums.begin(), nums.end());
    do {
        results.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));

    return results;
}

TEST_CASE("T1") {
    Solution sol;

    auto in = std::vector({1, 2, 3});
    auto out = generatePermutations(in);

    REQUIRE(sol.permute(in) == out);
};

TEST_CASE("T2") {
    Solution sol;

    auto in = std::vector({0, 1});
    auto out = matrix({{0, 1}, {1, 0}});

    REQUIRE(sol.permute(in) == out);
};

TEST_CASE("T3") {
    Solution sol;

    auto in = std::vector({1});
    auto out = matrix({{1}});

    REQUIRE(sol.permute(in) == out);
};

TEST_CASE("T4") {
    Solution sol;

    auto in = std::vector({2, 2, 2});
    auto out = matrix({{2, 2, 2}});

    REQUIRE(sol.permute(in) == out);
};