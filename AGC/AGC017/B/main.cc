#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long a, b, c, d;  
  cin >> n >> a >> b >> c >> d;

  for (int i = 0; i < n; ++i) {
    if (b - a >= c * i - d * (n - 1 - i) && b - a <= d * i - c * (n - 1 - i)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
