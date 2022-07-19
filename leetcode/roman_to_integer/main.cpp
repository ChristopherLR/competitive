#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
  public:
    int romanToInt(std::string s){
      int sum = 0;
      int len = s.length();
      if (len == 0) return 0;
      if (len == 1) return map_.at(s[0]);

      for (int i = 0; i < len - 1; i++){
        int first = map_.at(s[i]);
        int second = map_.at(s[i+1]);
        if (first < second) { 
          sum += second - first; 
          i += 1;
          if (i == len - 2) sum += map_.at(s[i+1]);
        } else {
          sum += first;
          if (i == len - 2) sum += second;
        }
      }

      return sum;
    };

  private:
    const std::unordered_map<char, int> map_ = {
      { 'I', 1  },
      { 'V', 5  },
      { 'X', 10 },
      { 'L', 50 },
      { 'C', 100 },
      { 'D', 500 },
      { 'M', 1000 }
    };
};

int main(){
  Solution sol;
  std::cout << 1 << " " << sol.romanToInt("I") << std::endl;
  std::cout << 3 << " " << sol.romanToInt("III") << std::endl;
  std::cout << 58 << " " << sol.romanToInt("LVIII") << std::endl;
  std::cout << 1994 << " " << sol.romanToInt("MCMXCIV") << std::endl;
  std::cout << 1695 << " " << sol.romanToInt("MDCXCV") << std::endl;
  std::cin.get();
}