#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> row(n), column(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int p;
      cin >> p;
      if (--p < 0) continue;
      row[i] = p;
      column[j] = p;
    }
  }
  
  atcoder::fenwick_tree<int> bit_r(n), bit_c(n);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += bit_r.sum(row[i] + 1, n);
    bit_r.add(row[i], 1);
    res += bit_c.sum(column[i] + 1, n);
    bit_c.add(column[i], 1);
  }

  cout << res << endl;  
  return 0;
}
