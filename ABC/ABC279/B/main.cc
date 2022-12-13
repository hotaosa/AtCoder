#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool is_sub(string t, string s) {
  int len_t = t.length(), len_s = s.length();
  s += string(len_t, '0');
  for (int i = 0; i < len_s; ++i) {
    if (t == s.substr(i, len_t)) return true;
  }
  return false;
}

int main() {
  string s, t;
  cin >> s >> t;
  cout << (is_sub(t, s) ? "Yes" : "No" ) << endl;  
  return 0;
}
