#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  cout << (b == a * 2 || b == a * 2 + 1 ? "Yes" : "No" ) << endl;  
  return 0;
}
