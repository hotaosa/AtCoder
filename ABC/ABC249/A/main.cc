#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b, c, d, e, f, x;
  cin >> a >> b >> c >> d >> e >> f >> x;
  int d1 = b * (a * (x / (a + c)) + min(a, x % (a + c)));
  int d2 = e * (d * (x / (d + f)) + min(d, x % (d + f)));

  string res = "Draw";
  if (d1 > d2) res = "Takahashi";
  else if (d1 < d2) res = "Aoki";
  cout << res << endl;
  return 0;
}
