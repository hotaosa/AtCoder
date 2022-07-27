#include <iostream>
#include <random>
#include <algorithm>

#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  vector<bool> a_include(n * m + 1, false), b_include(n * m + 1, false);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a_include[a[i]]) { cout << "0" << endl; return 0; }
    a_include[a[i]] = true;
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    if (b_include[b[i]]) { cout << "0" << endl; return 0;}
    b_include[b[i]] = true;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
    
  mint res = 1;
  for (int num = n * m; num > 0; --num) {
    if (a_include[num] && b_include[num]) {
      continue;
    } else if (a_include[num]) {
      int x = b.end() - lower_bound(b.begin(), b.end(), num);
      res *= x;
    } else if (b_include[num]) {
      int x = a.end() - lower_bound(a.begin(), a.end(), num);
      res *= x;
    } else {
      int x = a.end() - lower_bound(a.begin(), a.end(), num);
      x *= b.end() - lower_bound(b.begin(), b.end(), num);
      res *= x - (n * m - num);
    }
  }
  cout << res.val() << endl;
  return 0;  
}
