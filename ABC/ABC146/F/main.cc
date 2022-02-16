#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr int INF = 1 << 30;

int op(int a, int b) {
  return min(a, b);
}
int e() {
  return INF;
}

int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;

  atcoder::segtree<int, op, e> seg(n + 1);
  seg.set(0, 0);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '1') continue;
    int left = max(0, i - m);
    seg.set(i, seg.prod(left, i) + 1);    
  }
  if (seg.get(n) >= INF) { cout << "-1" << endl; return 0; }

  int hand = seg.get(n), cur = n;
  vector<vector<int> > li(hand);
  for (int i = 0; i < n; ++i) if (seg.get(i) < hand) li[seg.get(i)].push_back(i);

  vector<int> res(hand);
  for (int i = hand - 1; i >= 0; --i) {  
    auto nx = lower_bound(li[i].begin(), li[i].end(), cur - m);
    res[i] = cur - *nx;    
    cur = *nx;
  }

  for (auto &p : res) cout << p << " ";  
  cout << endl;
  return 0;
}
