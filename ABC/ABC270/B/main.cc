#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool exist_between(int a, int b, int c) {
  if (a < b && a > c) return true;
  if (a > b && a < c) return true;
  return false;
}

int main() {
  int x, y, z;
  cin >> x >> y >> z;

  if (!exist_between(y, 0, x)) {
    cout << abs(x) << endl;
    return 0;
  }

  if (!exist_between(y, 0, z)) {
    cout << abs(z) + abs(x - z) << endl;
    return 0;
  }

  cout << "-1" << endl;  
  return 0;
}
