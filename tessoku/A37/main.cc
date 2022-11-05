#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m, b;
  cin >> n >> m >> b;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    sum += a;
  }

  long long res = 0;
  for (int i = 0; i < m; ++i) {
    int c;
    cin >> c;
    res += (c + b) * n + sum;
  }
  cout << res << endl;  
  return 0;
}
