#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;

  long long res = n - 1;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      long long j = n / i;
      res = min(res, i + j - 2);
    }
  }

  cout << res << endl;  
  return 0;
}
