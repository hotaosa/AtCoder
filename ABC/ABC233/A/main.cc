#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  cout << max(0, (y - x + 9) / 10) << endl;
  return 0;
}
