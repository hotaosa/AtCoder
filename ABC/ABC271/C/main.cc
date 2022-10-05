#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  auto judge = [&](int k) -> bool {
    int cnt = upper_bound(a.begin(), a.end(), k) - a.begin();
    return cnt + (n - cnt) / 2 >= k;
  };

  int l = 0, r = n + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (judge(m)) l = m;
    else r = m;
  }

  cout << l << endl;  
  return 0;
}
