#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (auto &p : x) cin >> p;

  int res = 1 << 30;
  for (int i = 1; i <= 100; ++i) {
    int cur = 0;
    for (int j = 0; j < n; ++j) {
      cur += (x[j] - i) * (x[j] - i);
    }
    res = min(res, cur);
  }
  cout << res << endl;  
  return 0;
}
