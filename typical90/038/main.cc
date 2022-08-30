#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  const long long MAX = 1e18;
  long long a, b;
  cin >> a >> b;
  long long g = __gcd(a, b);
  if (a / g > MAX / b) cout << "Large" << endl;
  else cout << a / g * b << endl;  
  return 0;
}
