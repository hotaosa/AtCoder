#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int cnt1 = a[r] - a[--l];
    int cnt2 = r - l - cnt1;
    if (cnt1 > cnt2) cout << "win" << endl;
    else if (cnt1 < cnt2) cout << "lose" << endl;
    else cout << "draw" << endl;
  }
  
  return 0;
}
