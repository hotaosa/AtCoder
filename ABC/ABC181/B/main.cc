#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    res += (b + a) * (b - a + 1) / 2;
  }
  cout << res << endl;  
  return 0;
}
