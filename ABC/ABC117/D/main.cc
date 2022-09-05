#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<int> > cnt(40, vector<int>(2, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 40; ++j) {
      if (a[i] & (1LL << j)) ++cnt[j][1];
      else ++cnt[j][0];
    }
  }
  
  long long x = 0;
  for (int i = 39; i >= 0; --i) {
    if ((x | (1LL << i)) > k) continue;
    if ((x | (1LL << i)) <= k && cnt[i][0] > cnt[i][1]) x |= (1LL << i);
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) res += x ^ a[i];
  cout << res << endl;
  return 0;
}
