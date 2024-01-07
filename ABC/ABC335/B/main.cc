#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; i + j <= n; ++j) {
      for (int k = 0; i + j + k <= n; ++k) {
        cout << i << " " << j << " " << k << endl;
      }
    }
  }

  return 0;
}
