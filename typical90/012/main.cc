#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w, q;
  cin >> h >> w >> q;

  vector<vector<bool> > is_red(h, vector<bool>(w, false));
  atcoder::dsu uf(h * w);
  const int dr[] = {1, 0, -1, 0};
  const int dc[] = {0, 1, 0, -1};
  
  while (q--) {
    int qi;
    cin >> qi;
    if (qi == 1) {
      int r, c;
      cin >> r >> c;
      is_red[--r][--c] = true;
      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
        if (is_red[nr][nc]) uf.merge(r * w + c, nr * w + nc);
      }
    } else {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      --ra; --ca; --rb; --cb;
      cout << (is_red[ra][ca] && uf.same(ra * w + ca, rb * w + cb) ? "Yes" : "No" ) << endl;
    }
  }
  return 0;
}
