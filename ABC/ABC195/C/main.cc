#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;

  long long res = 0, base = 1;
  int cnt = 0;
  while (base <= n) {
    long long nx = base * 1000 - 1;
    res += (min(nx, n) - base + 1) * cnt;
    base *= 1000;
    ++cnt;
  }

  cout << res << endl;  
  return 0;
}
