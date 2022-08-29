#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  set<string> se1, se2;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s[0] != '!') se1.insert(s);
    else se2.insert(s.substr(1, s.size() - 1));
  }

  for (auto s : se1) {
    if (se2.count(s)) {
      cout << s << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;  
  return 0;
}
