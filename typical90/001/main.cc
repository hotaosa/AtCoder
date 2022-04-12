#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, l, k;
  cin >> n >> l >> k;

  vector<int> a(n);
  for (auto &p : a) cin >> p;

  auto judge = [&](int len) -> bool {
    int cnt = 0, cur = 0;
    for (int nx : a) {
      if (nx - cur >= len && l - nx >= len) {
        ++cnt;
        cur = nx;
      }
    }
    return cnt >= k;
  };

  int left = 0, right = l + 1;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (judge(mid)) left = mid;
    else right = mid;
  }
  cout << left << endl;
  return 0;
}
