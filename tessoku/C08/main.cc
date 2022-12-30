#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> s(n);
  vector<int> t(n);

  for (int i = 0; i < n; ++i) cin >> s[i] >> t[i];

  string res = "";
  for (int i = 0; i < 10000; ++i) {
    string cur = to_string(i);
    cur = string(4 - cur.size(), '0') + cur;

    bool satisfy = true;
    for (int j = 0; j < n; ++j) {
      int diff = 0;
      for (int k = 0; k < 4; ++k) if (cur[k] != s[j][k]) ++diff;
      if (t[j] == 1) {
        satisfy &= diff == 0;
      } else if (t[j] == 2) {
        satisfy &= diff == 1;
      } else {
        satisfy &= diff > 1;
      }
    }

    if (satisfy) {
      if (res == "") {
        res = cur;
      } else {
        res = "Can't Solve";
        break;
      }
    }
  }

  cout << res << endl;
  return 0;
}
