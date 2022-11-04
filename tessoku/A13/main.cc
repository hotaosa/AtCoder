#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int j = upper_bound(a.begin(), a.end(), k + a[i]) - a.begin();
    res += max(0, j - i - 1);
  }

  cout << res << endl;  
  return 0;
}
