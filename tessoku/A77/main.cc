#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  auto judge = [&](int x) -> bool {
    int cnt = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= cur + x) {
        cur = a[i];
        if (++cnt == k && l - cur >= x) return true;
      }
    }
    return false;
  };

  int ok = 0, ng = l + 1;
  while (ng - ok > 1) {
    int m = (ok + ng) / 2;
    if (judge(m)) ok = m;
    else ng = m;
  }
  
  cout << ok << endl;
  return 0;
}
