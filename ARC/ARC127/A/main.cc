#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;
  long long res = 0;

  long long p = 1;
  while (p <= n) {
    long long u = 1;
    while (p * u <= n) {      
      res += min(u, n - p * u + 1);
      u *= 10;
    }
    p = p * 10 + 1;
  }
  cout << res << endl;  
  return 0;
}
