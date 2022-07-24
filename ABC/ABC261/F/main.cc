#include <iostream>
#include <map>
#include <vector>
#include <atcoder/fenwicktree>

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
  vector<int> c(n), x(n);
  for (auto &p : c) cin >> p;
  for (auto &p : x) cin >> p;

  int color_size = vcomp(c);
  int value_size = vcomp(x);
  
  vector<vector<int> > subvec(color_size);
  for (int i = 0; i < n; ++i) subvec[c[i]].push_back(x[i]);
  
  atcoder::fenwick_tree<int> ft(value_size);
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += ft.sum(x[i] + 1, value_size);
    ft.add(x[i], 1);
  }
  for (auto &vec : subvec) {
    if (vec.size() < 2) continue;
    int size = vcomp(vec);
    atcoder::fenwick_tree<int> subft(size);
    for (int i = 0; i < vec.size(); ++i) {
      res -= subft.sum(vec[i] + 1, size);
      subft.add(vec[i], 1);
    }
  }

  cout << res << endl;
  return 0;  
}