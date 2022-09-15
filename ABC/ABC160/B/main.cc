#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int x;
  cin >> x;

  int res = x / 500 * 1000 + (x % 500) / 5 * 5;
  cout << res << endl;  
  return 0;
}
