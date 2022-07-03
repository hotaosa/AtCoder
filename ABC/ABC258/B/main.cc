#include <iostream>
#include <vector>
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint;

int main() {
  int n;
  cin >> n;
  mint::set_mod(n);

  vector<vector<long long> > a(n, vector<long long>(n));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) a[i][j] = s[j] - '0';
  }

  int dr[] = {1, 1, 1, 0, 0, -1, -1, -1};
  int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  long long res = 0;
  for (int sr = 0; sr < n; ++sr) {
    for (int sc = 0; sc < n; ++sc) {      
      for (int i = 0; i < 8; ++i) {
        mint r = sr, c = sc;
        long long cur = a[r.val()][c.val()];
        for (int cnt = 0; cnt < n - 1; ++cnt) {
          r += dr[i];
          c += dc[i];
          cur = cur * 10 + a[r.val()][c.val()];
        }
        res = max(res, cur);
      }
    }
  }
  cout << res << endl;
  return 0;
}