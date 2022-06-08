#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<pair<int, int> > latest(n, {0, 0});
  vector<tuple<int, int, long long> > add_query;
  vector<int> lq, rq, inival, c;

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      long long x;
      cin >> l >> r >> x;
      add_query.emplace_back(--l, --r, x);
    } else if (t == 2) {
      int p;
      long long x;
      cin >> p >> x;
      latest[--p] = {add_query.size(), x};
    } else {
      int i, j;
      cin >> i >> j;
      lq.push_back(latest[--i].first);
      rq.push_back(add_query.size());
      inival.push_back(latest[i].second);
      c.push_back(--j);
    }
  }

  q = lq.size();    
  const int sq = max(1, int(m / sqrt(q)));
  vector<int> qi(q);
  for (int i = 0; i < q; ++i) qi[i] = i;
  sort(qi.begin(), qi.end(), [&](int i, int j) {
    if (lq[i] / sq != lq[j] / sq) return lq[i] < lq[j];
    else if (lq[i] / sq & 1) return rq[i] > rq[j];
    return rq[i] < rq[j];
  });

  atcoder::fenwick_tree<long long> bit(m + 1);
    
  auto add = [&](int id) -> void {
    int l = get<0>(add_query[id]);
    int r = get<1>(add_query[id]);
    long long val = get<2>(add_query[id]);
    bit.add(l, val);
    bit.add(r + 1, -val);
  };
  
  auto del = [&](int id) -> void {    
    int l = get<0>(add_query[id]);
    int r = get<1>(add_query[id]);
    long long val = get<2>(add_query[id]);
    bit.add(l, -val);
    bit.add(r + 1, val);    
  };

  vector<long long> res(q);
  int nl = 0, nr = 0;
  for (int i : qi) {    
    while (nl > lq[i]) add(--nl);
    while (nr < rq[i]) add(nr++);
    while (nl < lq[i]) del(nl++);
    while (nr > rq[i]) del(--nr);
    res[i] = inival[i] + bit.sum(0, c[i] + 1);
  }

  for (int i = 0; i < q; ++i) cout << res[i] << endl;
  return 0;
}
