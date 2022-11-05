#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  bool possible = k >= 2 * (n - 1) && !(k & 1);
  cout << (possible ? "Yes" : "No" ) << endl;  
  return 0;
}
