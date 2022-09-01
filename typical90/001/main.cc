#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  auto judge = [&](int m) -> bool {
    int cnt = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] - b >= m) {
        b = a[i];
        ++cnt;
      }
    }
    if (cnt < k) return false;
    return cnt > k || l - b >= m;
  };

  int left = 1, right = l + 1;
  while (right - left > 1) {
    int mid = (right + left) / 2;
    if (judge(mid)) left = mid;
    else right = mid;
  }

  cout << left << endl;
  return 0;
}
