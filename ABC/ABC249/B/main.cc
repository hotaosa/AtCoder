#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  cin >> s;

  set<char> se, SE;
  for (auto c : s) {
    if (c >= 'a' && c <= 'z' && !se.insert(c).second) { cout << "No" << endl; return 0; }
    if (c >= 'A' && c <= 'Z' && !SE.insert(c).second) { cout << "No" << endl; return 0; }
  }
  cout << (se.empty() || SE.empty()? "No" : "Yes" ) << endl;  
  return 0;
}
