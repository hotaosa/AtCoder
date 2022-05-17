#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n * a; ++i) {
    for (int j = 0; j < n * b; ++j) {
      cout << (((j / b) + (i / a)) & 1 ? '#' : '.');
    }
    cout << endl;
  }
  return 0;
}
