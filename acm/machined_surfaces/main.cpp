#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  int num_lines = 1;

  while (cin >> num_lines && num_lines != 0) {
    if (!num_lines)
      break;

    int b_arr[num_lines];
    string line;
    getline(cin, line);
    int i = 0, start = 0, end = 0, b_count = 0, smallest = 128, open_space = 0;

    for (; i < num_lines; i++) {
      getline(cin, line);
      start = line.find_first_of(' ');
      end = line.find_last_of(' ');

      b_count = (start == -1) ? 0 : end - start + 1;
      if (b_count < smallest)
        smallest = b_count;
      b_arr[i] = b_count;
    }

    for (i = 0; i < num_lines; i++) {
      open_space += b_arr[i] - smallest;
    }

    cout << open_space << endl;
  }
  return 0;
}
