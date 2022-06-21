#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int small = 1, large = n * n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << (i & 1 ? large-- : small++) << " ";
    }
    cout << endl;
  }
  return 0;
}