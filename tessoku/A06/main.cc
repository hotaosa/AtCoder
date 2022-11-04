#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << a[r] - a[--l] << endl;
  }  
  
  return 0;
}
