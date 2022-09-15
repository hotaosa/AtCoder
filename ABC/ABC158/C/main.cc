#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  for (int i = 1; i <= 10000; ++i) {
    int c = i * 8 / 100;
    int d = i * 10 / 100;
    if (c == a && d == b) { cout << i << endl; return 0; }
  }
  cout << "-1" << endl;  
  return 0;
}
