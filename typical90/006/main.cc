#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

pair<int, int> op(pair<int, int> a, pair<int, int> b) {
  return min(a, b);
}
pair<int, int> e() {
  return {INF, INF};
}

using segtree = atcoder::segtree<pair<int, int>, op, e>;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  segtree seg(n);
  for (int i = 0; i < n; ++i) seg.set(i, {s[i] - 'a', i});

  string res = "";
  int l = 0;
  while (res.size() < k) {
    int r = n - k + 1 + res.size();
    auto mn = seg.prod(l, r);
    res += ('a' + mn.first);
    l = mn.second + 1;
  }
  cout << res << endl;  
  return 0;
}
