#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool comp(pair<int, int> lhs, pair<int, int> rhs) {
  if (lhs.first != rhs.first) return lhs.first < rhs.first;
  else return lhs.second > rhs.second;
}

int vcomp(vector<int> &v) {
  map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz= 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

int main() {
  int n;
  cin >> n;

  vector<int> ab(n * 2);
  for (auto &p : ab) cin >> p;
  int sz = vcomp(ab);

  vector<pair<int, int> > vp(n);
  for (int i = 0; i < n; ++i) {
    vp[i].first = ab[i];
    vp[i].second = ab[i + n];
  }
  sort(vp.begin(), vp.end(), comp);  

  atcoder::fenwick_tree<int> bit(sz);
  long long res = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && vp[i] == vp[i - 1]) ++cnt;
    else cnt = 0;
    int b = vp[i].second;
    bit.add(b, 1);
    res += bit.sum(b, sz) + cnt;
  }

  cout << res << endl;  
  return 0;
}
