#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b) {
    cout << '=' << endl;
  } else if (c & 1) {
    cout << (a > b ? '>' : '<') << endl;
  } else if (abs(a) == abs(b)) {
    cout << '=' << endl;
  } else {
    cout << (abs(a) > abs(b) ? '>' : '<') << endl;
  }
  return 0;
}
