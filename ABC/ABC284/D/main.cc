#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

pair<long long, long long> solve(long long n) {
  for (long long i = 2; i * i * i <= n; ++i) {
    if (n % (i * i) == 0) {
      return {i, n / (i * i)};
    }
    if (n % i == 0) {
      return {(long long)round(sqrtl(n / i)), i};
    }
  }
  return {-1, -1};
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    auto [p, q] = solve(n);
    cout << p << " " << q << endl;
  }
  
  return 0;
}
