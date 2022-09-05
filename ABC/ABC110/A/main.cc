#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int res = a * 10 + b + c;
  res = max(res, b * 10 + a + c);
  res = max(res, c * 10 + a + b);
  cout << res << endl;  
  return 0;
}
