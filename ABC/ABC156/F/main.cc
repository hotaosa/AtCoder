#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int k, q;
  cin >> k >> q;
  vector<long long> d(k + 1, 0);
  for (int i = 1; i <= k; ++i) cin >> d[i];
  
  while (q--) {    
    long long n, x, m;
    cin >> n >> x >> m;
    long long res = --n;
    vector<long long> md(k + 1, 0);
    vector<long long> zero(k + 1, 0);    
    for (int i = 1; i <= k; ++i) {
      md[i] = md[i - 1] + (d[i] % m);
      zero[i] = zero[i - 1] + (d[i] % m == 0 ? 1 : 0);
    }
    res -= n / k * zero[k] + zero[n % k];
    long long sum = x + n / k * md[k] + md[n % k];
    res -= sum / m - x / m;
    cout << res << endl;
  }  
  return 0;
}
