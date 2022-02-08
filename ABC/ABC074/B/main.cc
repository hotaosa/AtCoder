#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (auto &p : x) cin >> p;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += min(x[i], abs(k - x[i])) * 2;
  }
  cout << res << endl;
  return 0;
}
