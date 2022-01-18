#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto &p : a) cin >> p;
  sort(a.begin(), a.end());

  while (q--) {
    int x;
    cin >> x;
    cout << a.end() - lower_bound(a.begin(), a.end(), x) << endl;
  }
  return 0;
}
