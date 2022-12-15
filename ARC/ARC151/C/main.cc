#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  int m;
  cin >> n >> m;

  vector<long long> x(m);
  vector<int> y(m);
  for (int i = 0; i < m; ++i) cin >> x[i] >> y[i];

  if (m == 0) {
    cout << (n & 1LL ? "Takahashi" : "Aoki") << endl;
    return 0;
  }

  long long xsum = 0;
  for (int i = 1; i < m; ++i) {
    if (x[i] - x[i - 1] > 1) {
      xsum ^= y[i] == y[i - 1];
    }
  }
  xsum ^= x[0] - 1;
  xsum ^= n - x.back();

  cout << (xsum ? "Takahashi" : "Aoki") << endl;
  return 0;
}
