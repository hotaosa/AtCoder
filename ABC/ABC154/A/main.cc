#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;

  if (u == s) --a;
  else --b;

  cout << a << " " << b << endl;  
  return 0;
}
