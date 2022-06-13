#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];  

  auto divisor = [&](long long k) -> vector<long long> {
    vector<long long> div;
    for (long long i = 1; i * i <= k; ++i) {
      if (k % i == 0) {
        div.push_back(i);
        if (k / i != i) div.push_back(k / i);
      }
    }
    return div;
  };

  auto judge = [&](long long da, long long db) -> bool {
    for (int i = 1; i < n; ++i) {      
      if (a[i] % da == 0 && b[i] % db == 0) continue;
      if (a[i] % db == 0 && b[i] % da == 0) continue;
      return false;
    }
    return true;
  };
    
  vector<long long> div_a = divisor(a[0]);
  vector<long long> div_b = divisor(b[0]);

  long long res = 1;
  for (auto da : div_a) {
    for (auto db : div_b) {
      if (judge(da, db)) res = max(res, da * db / __gcd(da, db));
    }
  }

  cout << res << endl;  
  return 0;
}
