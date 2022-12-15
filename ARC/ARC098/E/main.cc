#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

int main() {
  int n, k, q;
  cin >> n >> k >> q;

  vector<int> a(n);
  for (auto &p : a) cin >> p;

  auto func = [&](int x) -> int {
    priority_queue<int, vector<int>, greater<> > pque1, pque2;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= x) {
        pque1.emplace(a[i]);
      } else {
        while ((int)pque1.size() >= k) {
          pque2.emplace(pque1.top());
          pque1.pop();
        }
        pque1 = priority_queue<int, vector<int>, greater<> >();
      }
    }
    while ((int)pque1.size() >= k) {
      pque2.emplace(pque1.top());
      pque1.pop();
    }

    int ret = INF;
    if ((int)pque2.size() < q) return ret;

    for (int i = 0; i < q; ++i) {
      ret = pque2.top();
      pque2.pop();
    }
    return ret - x;
  };

  int res = INF;
  for (int i = 0; i < n; ++i) res = min(res, func(a[i]));
  cout << res << endl;
  return 0;
}
