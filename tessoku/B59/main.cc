#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) { cin >> p; --p; }

  atcoder::fenwick_tree<int> bit(n);
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += bit.sum(a[i] + 1, n);
    bit.add(a[i], 1);
  }

  cout << res << endl;  
  return 0;
}
