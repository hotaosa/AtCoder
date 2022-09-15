#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n, a, b;
  cin >> n >> a >> b;

  long long res = n / (a + b) * a + min(a, n % (a + b));
  cout << res << endl;  
  return 0;
}
