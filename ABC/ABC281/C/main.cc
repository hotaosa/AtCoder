#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long t;
  cin >> n >> t;

  vector<long long> sum(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> sum[i];
    sum[i] += sum[i - 1];
  }

  t %= sum.back();
  auto p = lower_bound(sum.begin(), sum.end(), t);

  cout << p - sum.begin() << " " << t - *(--p) << endl;
  return 0;
}
