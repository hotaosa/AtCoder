#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n;
  cin >> n;

  int res = 0;
  map<int, int> mp;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (mp[a]++ & 1) ++res;
  }

  cout << res << endl;
  return 0;
}
