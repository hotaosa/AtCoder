#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  swap(x, y);
  swap(x, z);
  cout << x << " " << y << " " << z << endl;
  return 0;
}
