#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a * a + b * b < c * c ? "Yes" : "No" ) << endl;  
  return 0;
}
