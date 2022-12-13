#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int h, w, m;
  cin >> h >> w >> m;

  vector<int> obj_r(h, w), obj_c(w, h);
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pque;

  for (int i = 0; i < m; ++i) {
    int r, c;
    cin >> r >> c;
    pque.emplace(--r, --c);
    chmin(obj_r[r], c);
    chmin(obj_c[c], r);
  }
  for (int c = obj_r[0]; c < w; ++c) pque.emplace(0, c);

  long long res = 0;
  for (int c = 0; c < obj_r[0]; ++c) {
    res += obj_c[c];
  }

  atcoder::fenwick_tree<int> ft(w);
  for (int r = 1; r < obj_c[0]; ++r) {
    while (!pque.empty() && pque.top().first == r - 1) {
      auto [_, c] = pque.top();
      pque.pop();
      if (ft.sum(c, c + 1) == 0) ft.add(c, 1);
    }
    res += ft.sum(0, obj_r[r]);
  }

  cout << res << endl;
  return 0;
}
