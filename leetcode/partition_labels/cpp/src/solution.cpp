#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    // Runtime 0ms, Memory 6MB
    std::vector<int> partitionLabels(std::string s) {
        int max_idx[26]{0};
        for (int i = 0; i < s.size(); i++) max_idx[s[i] - 'a'] = i;

        std::vector<int> partitions;
        int max = -1, last = 0;
        for (int i = 0; i < s.size(); i++){
            max = std::max(max_idx[s[i] - 'a'], max);
            if (i == max){
                partitions.push_back(max - last + 1);
                last = i + 1;
            }
        }
        return partitions;
    }
};

TEST_CASE("T1") {
    Solution sol;
    REQUIRE(sol.partitionLabels("ababcbacadefegdehijhklij") ==
            std::vector{9, 7, 8});
};

TEST_CASE("T2") {
    Solution sol;
    REQUIRE(sol.partitionLabels("eccbbbbdec") == std::vector{10});
};


TEST_CASE("bceacbacdbbadea") {
    Solution sol;
    REQUIRE(sol.partitionLabels("bceacbacdbbadea") == std::vector{15});
};