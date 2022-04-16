#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long g = __gcd(a, __gcd(b, c));
  cout << (a + b + c) / g - 3 << endl;
  return 0;
}
