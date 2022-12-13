#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool match(vector<string> vs, vector<string> vt) {
  sort(vs.begin(), vs.end());
  sort(vt.begin(), vt.end());
  for (int i = 0; i < (int)vs.size(); ++i) {
    if (vs[i] != vt[i]) return false;
  }
  return true;
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> vs(w, string(h, '0')), vt(w, string(h, '0'));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) {
      vs[j][i] = s[j];
    }
  }
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) {
      vt[j][i] = s[j];
    }
  }

  cout << (match(vs, vt) ? "Yes" : "No" ) << endl;  
  return 0;
}
