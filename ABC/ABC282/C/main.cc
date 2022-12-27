#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  bool b = false;
  for (auto &&c : s) {
    if (c == '\"') b = !b;
    if (!b && c == ',') c = '.';
  }

  cout << s << endl;  
  return 0;
}
