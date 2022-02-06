#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long w;
  cin >> n >> w;
  vector<int> s(n), t(n);
  vector<long long> p(n);
  int ma_t = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> t[i] >> p[i];
    ma_t = max(ma_t, t[i]);
  }
  vector<long long> sum(ma_t + 1, 0);
  for (int i = 0; i < n; ++i) {
    sum[s[i]] += p[i];
    sum[t[i]] -= p[i];
  }
  bool possible = true;
  for (int i = 0; i <= ma_t; ++i) {
    if (i > 0) sum[i] += sum[i - 1];
    possible &= sum[i] <= w;
  }
  cout << (possible ? "Yes" : "No" ) << endl;
  return 0;
}
