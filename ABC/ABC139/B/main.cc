#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  --a; --b;
  cout << (b + a - 1) / a << endl;
  return 0;
}
