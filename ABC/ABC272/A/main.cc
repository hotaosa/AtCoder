#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    res += a;
  }
  cout << res << endl;  
  return 0;
}
