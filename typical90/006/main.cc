#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  vector<vector<int> > ch(n, vector<int>(26, 1 << 30));
  ch[n - 1][s.back() - 'a'] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) ch[i][j] = ch[i + 1][j];
    ch[i][s[i] - 'a'] = i;
  }

  string res = "";
  int pos = 0;

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (ch[pos][j] <= n - k + i) {
        res += char('a' + j);
        pos = ch[pos][j] + 1;
        break;
      }
    }
  }

  cout << res << endl;  
  return 0;
}
