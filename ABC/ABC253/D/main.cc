#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long func(long long n, long long a) {
  return a * (n / a + 1) * (n / a) / 2;
}

int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long c = a * b / __gcd(a, b);

  long long res = func(n, 1) - func(n, a) - func(n, b) + func(n, c);
  cout << res << endl;  
  return 0;
}
