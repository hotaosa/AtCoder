#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int h, w;
  cin >> h >> w;

  vector<string> res;
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w - 1; ++j) {
      if (s[j] == 'T' && s[j + 1] == 'T') {
        s[j] = 'P';
        s[j + 1] = 'C';
      }
    }
    res.push_back(s);
  }

  for (auto r : res) cout << r << endl;
  return 0;
}
