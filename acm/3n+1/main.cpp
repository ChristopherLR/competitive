#include <iostream>
#include <vector>

using namespace std;

vector<unsigned int> construct(unsigned int n) {
  vector<unsigned int> arr;
  arr.push_back(n);
  while (n != 1) {
    if (n % 2 == 1) {
      n = 3 * n + 1;
      arr.push_back(n);
    } else {
      n = n / 2;
      arr.push_back(n);
    }
  }
  return arr;
}

int main() {
  unsigned int i = 0, j = 0;
  unsigned int start = 0, end = 0;

  while (cin >> i && cin >> j) {
    int max = 0;
    start = (i <= j) ? i : j;
    end = (i <= j) ? j : i;

    for (unsigned int k = start; k <= end; k++) {
      unsigned int arr_size = construct(k).size();
      if (max < arr_size)
        max = arr_size;
    }
    cout << i << " " << j << " " << max << "\n";
  }
  return 0;
}
