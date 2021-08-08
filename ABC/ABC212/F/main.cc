#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<int> a(m), b(m), s(m), t(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> a[i] >> b[i] >> s[i] >> t[i];
    --a[i];
    --b[i];
    s[i] = s[i] * 2 + 1;
    t[i] = t[i] * 2 + 1;
  }

  std::vector<std::vector<std::pair<int, int> > > vp(n);
  for (int i = 0; i < m; ++i) vp[a[i]].push_back(std::make_pair(s[i], i));
  for (int i = 0; i < n; ++i) std::sort(vp[i].begin(), vp[i].end());

  std::vector<int> to(m, -1);
  for (int i = 0; i < m; ++i) {
    int v = b[i];
    auto it = std::lower_bound(vp[v].begin(), vp[v].end(), std::make_pair(t[i], 0));
    if (it == vp[v].end()) to[i] = i;
    else to[i] = it->second;
  }

  const int SIZE = 30;
  std::vector<std::vector<int> > db(SIZE, std::vector<int>(m, -1));
  for (int i = 0; i < m; ++i) db[0][i] = to[i];
  for (int i = 1; i < SIZE; ++i) {
    for (int j = 0; j < m; ++j) {
      db[i][j] = db[i - 1][db[i - 1][j]];
    }
  }

  for (int i = 0; i < q; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    --y;
    x *= 2;
    z *= 2;
    auto it = std::lower_bound(vp[y].begin(), vp[y].end(), std::make_pair(x, 0));
    if (it == vp[y].end() || it->first > z) { std::cout << y + 1 << std::endl; continue; }
    int cur = it->second;
    if (z < s[cur]) { std::cout << y + 1 << std::endl; continue; }
    if (z < t[cur]) { std::cout << a[cur] + 1 << " " << b[cur] + 1 << std::endl; continue; }
    for (int i = SIZE - 1; i >= 0; --i) {
      int next = db[i][cur];
      if (t[next] < z) cur = next;
    }

    int next = db[0][cur];
    if (s[next] > z) std::cout << b[cur] + 1 << std::endl;
    else if (t[next] > z) std::cout << a[next] + 1 << " " << b[next] + 1 << std::endl;
    else std::cout << b[next] + 1 << std::endl;
  }
  return 0;
}
