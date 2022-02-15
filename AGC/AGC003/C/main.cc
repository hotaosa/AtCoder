#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

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
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  vcomp(a);

  int res = 0;
  for (int i = 0; i < n; i += 2) if (a[i] & 1) ++res;
  cout << res << endl;
  return 0;
}
