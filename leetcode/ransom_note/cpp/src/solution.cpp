#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool canConstruct(std::string note, std::string magazine) {
    if (note.size() > magazine.size()) return false;

    int map[26] = {};
    for (char c : magazine) map[c - 'a'] += 1;
    for (char c : note) {
      if (map[c - 'a'] == 0) return false;
      map[c - 'a'] -= 1;
    }

    return true;
  };
};

TEST_CASE("T1"){
    Solution sol;
    REQUIRE(sol.canConstruct("a", "b") == false);
};

TEST_CASE("T2"){
    Solution sol;
    REQUIRE(sol.canConstruct("aa", "ab") == false);
};

TEST_CASE("T3") {
  Solution sol;
  REQUIRE(sol.canConstruct("aa", "aab") == true);
};

TEST_CASE("T4") {
  std::string ransom =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  std::string note =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  Solution sol;
  REQUIRE(sol.canConstruct(ransom, note) == true);
};
