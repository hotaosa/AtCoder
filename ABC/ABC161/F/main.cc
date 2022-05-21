#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;

  set<long long> res;
  res.insert(2);
  res.insert(n);
  if (n > 3) res.insert(n - 1);

  auto check = [&](long long k) -> void {
    long long nn = n;
    while (nn % k == 0) nn /= k;
    if (nn % k == 1) res.insert(k);
  };

  for (long long i = 2; i * i <= n; ++i) {
    if ((n - 1) % i == 0) { res.insert(i); res.insert((n - 1) / i); }
    if (n % i == 0) { check(i); check(n / i); }    
  }
  cout << res.size() << endl;
  return 0;
}
