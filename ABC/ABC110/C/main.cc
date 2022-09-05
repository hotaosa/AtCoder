#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  vector<vector<int> > vs, vt;
  for (char c = 'a'; c <= 'z'; ++c) {
    vector<int> v;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == c) v.push_back(i);
    }
    if (!v.empty()) vs.push_back(v);
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    vector<int> v;
    for (int i = 0; i < (int)t.size(); ++i) {
      if (t[i] == c) v.push_back(i);
    }
    if (!v.empty()) vt.push_back(v);
  }
  sort(vs.begin(), vs.end());
  sort(vt.begin(), vt.end());

  cout << (vs == vt ? "Yes" : "No" ) << endl;
  return 0;
}
