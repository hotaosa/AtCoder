#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n), t(n);
  for (int i = 0; i < n; ++i) cin >> s[i] >> t[i];

  for (int i = 0; i < n; ++i) {
    bool exist_s = false, exist_t = false;
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      if (s[i] == s[j] || s[i] == t[j]) exist_s = true;
      if (t[i] == s[j] || t[i] == t[j]) exist_t = true;
    }
    if (exist_s && exist_t) { cout << "No" << endl; return 0; }
  }
  cout << "Yes" << endl;
  return 0;
}
