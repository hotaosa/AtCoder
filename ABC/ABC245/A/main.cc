#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (a * 100 + b <= c * 100 + d ? "Takahashi" : "Aoki" ) << endl;
  return 0;
}
