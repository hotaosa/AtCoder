#include <iostream>
#include <string>
//
#include <atcoder/segtree>

using namespace std;

struct S {
  char c;
  int idx;
  bool operator<(const S &other) const {
    return make_pair(c, idx) < make_pair(other.c, other.idx);
  }
};
S Operate(S a, S b) { return min(a, b); }
S E() { return S{'{', -1}; }
using Segtree = atcoder::segtree<S, Operate, E>;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  Segtree seg(n);
  for (int i = 0; i < n; ++i) {
    seg.set(i, S{s[i], i});
  }

  string res = "";
  int l = 0, r = n - k + 1;
  for (int i = 0; i < k; ++i) {
    auto minimum = seg.prod(l, r);
    res += minimum.c;
    l = minimum.idx + 1;
    r = n - k + 2 + i;
  }

  cout << res << endl;
  return 0;
}
