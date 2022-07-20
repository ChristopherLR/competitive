#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
  public:
    int romanToInt(std::string s){
      int sum = 0;
      int len = s.length();
      if (len == 0) return 0;
      if (len == 1) return romanCharToInt(s[0]);

      for (int i = 0; i < len - 1; i++){
        int first = romanCharToInt(s[i]);
        int second = romanCharToInt(s[i+1]);
        if (first < second) { 
          sum += second - first; 
          i += 1;
          if (i == len - 2) sum += romanCharToInt(s[i+1]);
        } else {
          sum += first;
          if (i == len - 2) sum += second;
        }
      }

      return sum;
    };

  private:
    const int romanCharToInt(const char c) const {
      switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
      }
      return 0;
    };

    // const std::unordered_map<char, int> map_ = {
    //   { 'I', 1  },
    //   { 'V', 5  },
    //   { 'X', 10 },
    //   { 'L', 50 },
    //   { 'C', 100 },
    //   { 'D', 500 },
    //   { 'M', 1000 }
    // };
};

/// normal map: 30ms 8.7 MB
/// const map: 15ms 7.6 MB
/// const function: 16ms 6 MB

int main(){
  Solution sol;
  std::cout << 1 << " " << sol.romanToInt("I") << std::endl;
  std::cout << 3 << " " << sol.romanToInt("III") << std::endl;
  std::cout << 58 << " " << sol.romanToInt("LVIII") << std::endl;
  std::cout << 1994 << " " << sol.romanToInt("MCMXCIV") << std::endl;
  std::cout << 1695 << " " << sol.romanToInt("MDCXCV") << std::endl;
  std::cin.get();
}