#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, a, b ,c;
  cin >> n >> a >> b >> c;
  const int MAX = 10000;

  int res = MAX;
  for (int i = 0; i < MAX && a * i <= n; ++i) {
    for (int j = 0; j < MAX - i && a * i + b * j <= n; ++j) {
      int m = n - a * i - b * j;
      if (m % c == 0) res = min(res, i + j + m / c);
    }
  }

  cout << res << endl;  
  return 0;
}
