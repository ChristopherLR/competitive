#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>
#include <numeric>

class Solution {
  public:
    // Runtime 12ms, Memory 7.9MB
    // int maximumWealth(std::vector<std::vector<int>>& accounts) {
    //     int max = 0;
    //     for (auto& account : accounts){
    //         int sum = std::accumulate(account.begin(), account.end(), 0);
    //         if (sum > max) max = sum;
    //     }
    //     return max;
    // }

    // Runtime 10ms, Memory 7.8MB
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        unsigned int max = 0, sum = 0, i = 0, j = 0, numAccounts = accounts.size(), accountEntries = accounts[0].size();

        for (i = 0; i < numAccounts; i++){
            sum = 0;
            for (j = 0; j < accountEntries; j++) sum += accounts[i][j];
            if (sum > max) max = sum;
        }

        return max;
    }
};
