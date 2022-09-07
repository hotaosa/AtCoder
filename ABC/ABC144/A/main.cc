#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (max(a, b) <= 9) cout << a * b << endl;
  else cout << "-1" << endl;  
  return 0;
}
