#include <bit>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int b = 0;
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'o') b |= (1 << j);
    }
    v.emplace_back(b);
  }

  int res = n;
  for (int b = 1; b < (1 << n); ++b) {
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (!(b >> i & 1)) continue;
      for (int j = 0; j < m; ++j) {
        if (v[i] >> j & 1) cur |= (1 << j);
      }
    }
    if (__popcount(cur) == m) res = min(res, __popcount(b));
  }

  cout << res << endl;
  return 0;
}