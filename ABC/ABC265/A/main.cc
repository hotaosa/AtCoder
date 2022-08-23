#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int x, y, n;
  cin >> x >> y >> n;
  int res = min(x * n, n / 3 * y + (n % 3) * x);
  cout << res << endl;  
  return 0;
}
