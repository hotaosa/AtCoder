#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  if (s.size() > t.size()) cout << "No" << endl;
  else cout << (s == t.substr(0, s.size()) ? "Yes" : "No") << endl;  
  return 0;
}
