#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n, d;
  cin >> n >> d;
  vector<int> t(n);
  for (auto &p : t) cin >> p;

  int res = -1;
  for (int i = n - 1; i > 0; --i) {
    if (t[i] - t[i - 1] <= d) res = t[i];
  }

  cout << res << endl;
  return 0;
}
