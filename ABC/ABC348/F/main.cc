#pragma GCC optimize("O3")
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int b = 0;
      for (int k = 0; k < m; ++k) {
        b ^= a[i][k] == a[j][k];
      }
      res += b;
    }
  }
  cout << res << endl;
  return 0;
}