#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;
  bool black = max(abs(r - 8), abs(c - 8)) & 1;
  cout << (black ? "black" : "white") << endl;  
  return 0;
}
