#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int op(int a, int b) {
  return min(a, b);
}
int e() {
  return 1 << 30;
}

int main() {
  constexpr int SIZ = 200001;
  int n, q;
  cin >> n >> q;  

  vector<int> rate(n), pos(n);
  vector<multiset<int> > vs(SIZ);
  for (int i = 0; i < n; ++i) {
    cin >> rate[i] >> pos[i];    
    vs[--pos[i]].insert(rate[i]);
  }

  atcoder::segtree<int, op, e> seg(SIZ);
  for (int i = 0; i < SIZ; ++i) if (!vs[i].empty()) seg.set(i, *vs[i].rbegin());

  while (q--) {
    int c, d;
    cin >> c >> d;
    --c;
    --d;
    vs[pos[c]].erase(vs[pos[c]].find(rate[c]));
    vs[d].insert(rate[c]);
    seg.set(d, *vs[d].rbegin());
    if (!vs[pos[c]].empty()) seg.set(pos[c], *vs[pos[c]].rbegin());
    else seg.set(pos[c], 1 << 30);
    pos[c] = d;
    cout << seg.all_prod() << endl;
  }      
  return 0;
}
