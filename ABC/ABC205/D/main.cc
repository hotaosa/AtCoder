#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;
  
  auto solve = [&](long long k) -> long long {
    long long l = k, r = 1LL << 60;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      long long cnt = m - (lower_bound(a.begin(), a.end(), m) - a.begin());
      if (cnt > k) r = m;
      else l = m;
    }
    return l;
  };

  while (q--) {
    long long k;
    cin >> k;
    cout << solve(k) << endl;
  }  
  return 0;
}
