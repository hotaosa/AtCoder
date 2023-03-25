#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n, m;
  cin >> n >> m;
  
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  int res = 0;
  for (int i = 0; i < m; ++i) {
    int b;
    cin >> b;
    res += a[--b];
  }

  cout << res << endl;
  return 0;
}
