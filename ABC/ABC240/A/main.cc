#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (b > a) swap(a, b);
  cout << (a - b == 1 || a - b == 9 ? "Yes" : "No" ) << endl;
  return 0;
}
