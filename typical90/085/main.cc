#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long k;
  cin >> k;

  long long res = 0;
  vector<long long> divisor;
  for (long long i = 1; i * i <= k; ++i) {
    if (k % i == 0) {
      for (long long j = 1; j * j <= i; ++j) {
        if (i % j == 0) ++res;
      }
      if (k / i != i) {
        for (long long j = 1; j * j <= k / i; ++j) {
          if (k / i % j == 0 && k / i / j <= i) ++res;
        }
      }
    }
  }

  cout << res << endl;  
  return 0;
}
