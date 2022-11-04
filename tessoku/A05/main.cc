#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int res = 0;
  for (int i = 1; i <= min(n, k - 2); ++i) {
    for (int j = 1; j <= min(n, k - i - 1); ++j) {
      if (k - i - j <= n) ++res;
    }
  }

  cout << res << endl;  
  return 0;
}
