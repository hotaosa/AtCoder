#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > c) swap(a, c);
  cout << (b >= a && b <= c ? "Yes" : "No" ) << endl;
  return 0;
}
