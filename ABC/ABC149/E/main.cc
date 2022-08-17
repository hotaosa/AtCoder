#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;

  vector<long long> a(n);
  for (auto &p : a) cin >> p;
  sort(a.begin(), a.end());

  vector<long long> sum(n);
  sum[0] = a[0];
  for (int i = 1; i < n; ++i) sum[i] = sum[i - 1] + a[i];

  auto judge = [&](long long k) -> bool {
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += a.end() - lower_bound(a.begin(), a.end(), k - a[i]);
    }
    return cnt >= m;
  };

  long long l = 2, r = 1e10 + 1;
  while (r - l > 1) {
    long long m = (r + l) / 2LL;
    if (judge(m)) l = m;
    else r = m;
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int pos = upper_bound(a.begin(), a.end(), l - a[i]) - a.begin();
    int cnt = n - pos;
    m -= cnt;
    res += a[i] * cnt + sum.back() - (pos > 0 ? sum[pos - 1] : 0);
  }
  res += l * m;
  cout << res << endl;  
  return 0;
}
