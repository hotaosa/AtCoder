#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, q;
  long long x;
  cin >> n >> q >> x;

  vector<long long> w(n);
  for (auto &p : w) cin >> p;

  vector<long long> sum(2 * n + 1, 0);
  for (int i = 1; i <= 2 * n; ++i) sum[i] = sum[i - 1] + w[(i - 1) % n];

  vector<vector<int> > db(41, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    auto p = lower_bound(sum.begin(), sum.end(), sum[i] + x % sum[n]);
    db[0][i] = (p - sum.begin()) % n;
  }
  for (int i = 1; i <= 40; ++i) for (int j = 0; j < n; ++j) db[i][j] = db[i - 1][db[i - 1][j]];

  auto solve = [&](long long k) -> long long {    
    int pos = 0;
    --k;
    for (int i = 40; i >= 0; --i) if (k & (1LL << i)) pos = db[i][pos];
    long long res = x / sum[n] * n;
    auto p = lower_bound(sum.begin(), sum.end(), sum[pos] + x % sum[n]);
    res += p - sum.begin() - pos;
    return res;
  };
  
  while (q--) {
    long long k;
    cin >> k;
    cout << solve(k) << endl;
  }
  return 0;
}