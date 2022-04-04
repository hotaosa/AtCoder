#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int x = 0, y = 0;
  for (int i = 0; i < 3; ++i) {
    int xi, yi;
    cin >> xi >> yi;
    x ^= xi;
    y ^= yi;
  }
  cout << x << " " << y << endl;
  return 0;
}
