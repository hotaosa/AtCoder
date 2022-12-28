#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> leader(n), place(n + q, -1), par(n + q, -1), size(n + q, 1);
  for (int i = 0; i < n; ++i) {
    leader[i] = i;
    place[i] = i;
  }

  int cnt = n;
  
  auto root = [&](auto root, int i) -> int {
    if (par[i] == -1) return i;
    else return par[i] = root(root, par[i]);
  };

  auto move = [&](int x, int y) -> void {
    int lx = leader[x], ly = leader[y];
    if (ly == -1) return;
    if (lx == -1) {
      leader[x] = ly;
      place[ly] = x;
      leader[y] = -1;
      return;
    }
    if (size[lx] >= size[ly]) {
      size[lx] += size[ly];
      par[ly] = lx;
    } else {
      size[ly] += size[lx];
      leader[x] = ly;
      par[lx] = ly;
      place[ly] = x;
    }
    leader[y] = -1;
  };

  auto push = [&](int x) -> void {
    int lx = leader[x];
    if (lx == -1) {
      leader[x] = cnt;
      place[cnt] = x;
    } else {
      ++size[x];
      par[cnt] = lx;
    }
    ++cnt;
  };

  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      int y;
      cin >> y;
      move(--x, --y);
    } else if (t == 2) {
      push(--x);
    } else {
      cout << place[root(root, --x)] + 1 << endl;
    }
  }
  
  return 0;
}
