#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m);
  for (int i = 0; i < m; ++i) cin >> l[i] >> r[i];
  vector<int> order(m);
  for (int i = 0; i < m; ++i) order[i] = i;
  sort(order.begin(), order.end(), [&](int i, int j) {
    if (l[i] != l[j]) return l[i] < l[j];
    return r[i] > r[j];
  });  

  long long res = 0;
  atcoder::fenwick_tree<int> bit(n + 1);
  for (int i : order) {
    res += bit.sum(l[i], --r[i]);
    bit.add(r[i], 1);
  }
  cout << res << endl;
  return 0;
}
