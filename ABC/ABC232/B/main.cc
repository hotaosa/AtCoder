#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

string rotate(string s) {
  string ret = "";
  for (char c : s) ret += 'a' + ((c - 'a' + 1) % 26);
  return ret;
}

int main() {
  string s, t;
  cin >> s >> t;
  if (s == t) { cout << "Yes" << endl; return 0; }

  for (int i = 0; i < 26; ++i) {
    s = rotate(s);
    if (s == t) { cout << "Yes" << endl; return 0; }
  }

  cout << "No" << endl;
  return 0;
}