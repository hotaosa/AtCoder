#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  n = ~n;
  int res = 0;
  while (n & 1) {
    ++res;
    n >>= 1;
  }
  cout << res << endl;
  return 0;
}