#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n;
  cin >> n;
  int b = 0;
  long long res = 1LL << 60;
  while (n >= (1LL << b)) {
    long long a = n / (1LL << b);
    long long c = n % (a * (1LL << b));
    res = min(res, a + b + c);
    ++b;
  }
  cout << res << endl;
  return 0;
}
