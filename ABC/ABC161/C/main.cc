#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  n %= k;
  set<long long> se;
  se.insert(n);
  long long res = n;
  while (true) {
    n = abs(k - n);
    res = min(res, n);
    if (!se.insert(n).second) break;
  }
  cout << res << endl;
  return 0;
}
