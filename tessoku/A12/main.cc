#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  auto judge = [&](int t) -> bool {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += t / a[i];
      if (cnt >= k) return true;
    }
    return false;
  };

  int l = 0, r = 1 << 30;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (judge(m)) r = m;
    else l = m;
  }

  cout << r << endl;  
  return 0;
}
