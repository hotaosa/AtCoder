#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n;
  cin >> n;

  vector<vector<long long> > pos(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    pos[--a].push_back(i);
  }

  long long res = 0;
  for (long long i = 2; i <= n; ++i) {
    res += (n - i + 1) * (i / 2);
  }

  vector<pair<int, long long> > vp;
  auto Add = [&](int idx) -> void {
    if (vp.empty()) {
      vp.emplace_back(idx, idx + 1);
      return;
    }
    auto p = lower_bound(vp.begin(), vp.end(), make_pair(n - idx, 0LL));
    if (p != vp.begin()) {
      res -= prev(p)->second;      
    }
    res -= (n - idx) * (vp.end() - p);
    vp.emplace_back(idx, vp.back().second + idx + 1);
  };

  for (int i = 0; i < n; ++i) {
    if (pos[i].empty()) continue;
    vp.clear();
    for (auto idx : pos[i]) {
      Add(idx);
    }
  }

  cout << res << endl;
  return 0;
}
