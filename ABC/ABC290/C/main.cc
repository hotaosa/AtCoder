#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto &p : a) cin >> p;
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  int res = 0;
  while (res < k && a[res] == res) res++;

  cout << res << endl;
  return 0;
}
