#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  int a, b;
  cin >> s >> a >> b;
  swap(s[--a], s[--b]);
  cout << s << endl;
  return 0;
}
