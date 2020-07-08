#include <iostream>
#include <string>
#include <unordered_map>

#define ASCII_9 0x39

void palin_type(std::string line) {
  int start = 0, end = line.length() - 1;
  char is_palin = 1, is_mirror = 1;
  std::unordered_map<char, char> map(
      {{'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'L', 'J'},
       {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
       {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'2', 'S'},
       {'3', 'E'}, {'5', 'Z'}, {'8', '8'}});

  while (start < end) {
    if (line[start] == line[end]) {
      start++;
      end--;
    } else {
      is_palin = 0;
      break;
    }
  }

  start = 0, end = line.length() - 1;
  while (start <= end) {
    if (line[start] == map[line[end]]) {
      start++;
      end--;
    } else {
      is_mirror = 0;
      break;
    }
  }

  if (is_palin && is_mirror) {
    std::cout << line << " -- is a mirrored palindrome." << std::endl;
  } else if (is_mirror) {
    std::cout << line << " -- is a mirrored string." << std::endl;
  } else if (is_palin) {
    std::cout << line << " -- is a regular palindrome." << std::endl;
  } else {
    std::cout << line << " -- is not a palindrome." << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  for (std::string line; std::getline(std::cin, line);) {
    palin_type(line);
  }
  return 0;
}
