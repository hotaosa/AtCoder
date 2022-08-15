#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

pair<int, int> op(pair<int, int> a, pair<int, int> b) {
  return min(a, b);
}
pair<int, int> e() {
  return {1 << 30, -1};
}
using segtree = atcoder::segtree<pair<int, int>, op, e>;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

vector<int> get_min_vec(vector<int> v, int k) {
  int n = v.size();
  vector<int> ret;
  segtree seg(n);
  for (int i = 0; i < n; ++i) seg.set(i, {v[i], i});
  int pos = 0;  
  while (pos + k < n) {
    auto pa = seg.prod(pos, pos + k + 1);
    ret.push_back(pa.first);
    k -= pa.second - pos;
    pos = pa.second + 1;
  }
  return ret;
}

vector<int> get_min_vec_pre(vector<int> v, int mn) {
  int n = v.size();
  vector<int> ret;
  segtree seg(n);
  for (int i = 0; i < n; ++i) seg.set(i, {v[i], i});
  int pos = 0;
  while(pos < n) {
    auto pa = seg.prod(pos, n);
    if (pa.first > mn) break;
    ret.push_back(pa.first);
    pos = pa.second + 1;
  }
  return ret;  
}

void chmin_vec(vector<int> &v1, vector<int> &v2) {
  int s1 = v1.size(), s2 = v2.size();
  for (int i = 0; i < min(s1, s2); ++i) {
    if (v1[i] < v2[i]) return;
    if (v1[i] > v2[i]) {
      v1 = v2;
      return;
    }
  }
  if (s2 < s1) v1 = v2;  
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  vector<int> res1 = get_min_vec(p, k);
  
  pair<int, int> mn = {n, n};
  for (int i = 1; i <= k; ++i) chmin(mn, {p[n - i], n - i});
  k -= n - mn.second;

  vector<int> p_pre, p_suf;
  for (int i = 0; i < mn.second; ++i) p_pre.push_back(p[i]);
  for (int i = mn.second; i < n; ++i) p_suf.push_back(p[i]);
  vector<int> suf = get_min_vec(p_pre, k);
  vector<int> res2 = get_min_vec_pre(p_suf, suf[0]);  
  for (int r : suf) res2.push_back(r);

  chmin_vec(res1, res2);
  for (int r : res1) cout << r << " ";
  cout << endl;
  return 0;
}
