#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<bool> > is_white(n, vector<bool>(n));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) is_white[i][j] = (s[j] == '.');
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i < n - 5) {
        int cnt = 0;
        for (int k = 0; k < 6; ++k) if (is_white[i + k][j]) ++cnt;
        if (cnt <= 2) { cout << "Yes" << endl; return 0; }
      }
      if (j < n - 5) {
        int cnt = 0;
        for (int k = 0; k < 6; ++k) if (is_white[i][j + k]) ++cnt;
        if (cnt <= 2) { cout << "Yes" << endl; return 0; }
      }
      if (i < n - 5 && j < n - 5) {
        int cnt = 0;
        for (int k = 0; k < 6; ++k) if (is_white[i + k][j + k]) ++cnt;
        if (cnt <= 2) { cout << "Yes" << endl; return 0; }
      }
      if (i < n - 5 && j > 4) {
        int cnt = 0;
        for (int k = 0; k < 6; ++k) if (is_white[i + k][j - k]) ++cnt;
        if (cnt <= 2) { cout << "Yes" << endl; return 0; }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
