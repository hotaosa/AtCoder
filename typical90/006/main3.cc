#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  vector nx(n + 1, vector<int>(26, n));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      nx[i][j] = nx[i + 1][j];
    }
    nx[i][s[i] - 'a'] = i;
  }

  string res = "";
  int l = 0;
  for (int r = n - k; r < n; ++r) {
    int c = -1, pos = -1;
    for (int j = 25; j >= 0; --j) {
      if (nx[l][j] <= r) {
        c = j;
        pos = nx[l][j];
      }
    }
    assert(c != -1);
    res += char('a' + c);
    l = pos + 1;
  }

  cout << res << endl;
  return 0;
}