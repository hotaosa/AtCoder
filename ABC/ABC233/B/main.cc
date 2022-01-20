#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int l, r;
  string s;
  cin >> l >> r >> s;  
  reverse(s.begin() + (l - 1), s.begin() + r);
  cout << s << endl;  
  return 0;
}
