#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int res = 0;
  while (n) {
    ++res;
    n /= k;
  }
  cout << res << endl;  
  return 0;
}
