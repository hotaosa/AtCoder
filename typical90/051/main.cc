#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  long long p;
  cin >> n >> k >> p;

  int nl = n / 2, nu = (n + 1) / 2;

  vector<long long> a(nl), b(nu);
  for (int i = 0; i < nl; ++i) cin >> a[i];
  for (int i = 0; i < nu; ++i) cin >> b[i];
  
  vector<vector<long long> > vec(k + 1);
  for (int bit = 0; bit < (1 << nl); ++bit) {
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < nl; ++i) {
      if (bit & (1 << i)) {
        sum += a[i];
        ++cnt;
      }
    }    
    if (cnt <= k) vec[cnt].push_back(sum);
  }  
  for (auto &v : vec) sort(v.begin(), v.end());

  long long res = 0;
  for (int bit = 0; bit < (1 << nu); ++bit) {
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < nu; ++i) {
      if (bit & (1 << i)) {
        sum += b[i];
        ++cnt;
      }
    }
    if (cnt > k) continue;
    res += upper_bound(vec[k - cnt].begin(), vec[k - cnt].end(), p - sum) - vec[k - cnt].begin();
  }

  cout << res << endl;
  return 0;
}
