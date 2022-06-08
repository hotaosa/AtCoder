#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  int res = 0;

  for (long long i = 1; i <= n; ++i) {
    long long k = i;
    for (long long j = 2; j * j <= k; ++j) while (k % (j * j) == 0) k /= j * j;
    for (long long j = 1; k * j * j <= n; ++j) ++res;
  }

  cout << res << endl;  
  return 0;
}
