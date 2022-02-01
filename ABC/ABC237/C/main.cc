#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool is_palindrome(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return t == s;
}

int main() {
  string s;
  cin >> s;
  int n = s.length();

  int pre = 0, suf = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') ++pre;
    else break;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'a') ++suf;
    else break;
  }

  if (pre > suf) { cout << "No" << endl; return 0; }
  int new_len = n - pre - suf;
  if (new_len <= 0) { cout << "Yes" << endl; return 0; }
  s = s.substr(pre, new_len);

  cout << (is_palindrome(s) ? "Yes" : "No" ) << endl;
  return 0;
}
