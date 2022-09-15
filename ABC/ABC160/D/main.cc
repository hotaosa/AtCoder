#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  --x; --y;

  vector<int> cnt(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int dist = min(j - i, abs(i - x) + abs(j - y) + 1);
      ++cnt[dist];
    }
  }

  for (int i = 1; i < n; ++i) cout << cnt[i] << endl;  
  return 0;
}
