#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;

  long long res = -INF;
  res = max(res, a * c);
  res = max(res, a * d);
  res = max(res, b * c);
  res = max(res, b * d);

  cout << res << endl;  
  return 0;
}
