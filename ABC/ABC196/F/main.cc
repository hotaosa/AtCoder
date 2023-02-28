#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  const int n = s.size(), m = t.size();
  vector<int> f1(n), f2(n), g1(m), g2(m);
  for (int i = 0; i < n; ++i) {
    f1[i] = s[i] - '0';
    f2[i] = '1' - s[i];
  }
  for (int i = 0; i < m; ++i) {
    g1[m - 1 - i] = '1' - t[i];
    g2[m - 1 - i] = t[i] - '0';
  }

  const auto h1 = atcoder::convolution(f1, g1);
  const auto h2 = atcoder::convolution(f2, g2);

  int res = m;
  for (int i = m - 1; i < n; ++i) {
    res = min(res, h1[i] + h2[i]);
  }

  cout << res << endl;
  return 0;
}
