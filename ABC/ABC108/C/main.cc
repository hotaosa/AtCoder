#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<long long> cnt(k, 0);
  for (int i = 1; i <= n; ++i) ++cnt[i % k];

  long long res = 0;
  for (int i = 0; i < k; ++i) {
    if (i * 2 % k == 0) res += cnt[i] * cnt[i] * cnt[i];
  }
  cout << res << endl;  
  return 0;
}
