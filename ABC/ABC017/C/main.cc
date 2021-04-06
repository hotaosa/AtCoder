#include <bits/stdc++.h>

int main() {
  const int INF = 1 << 30;
  
  int n, m;
  std::cin >> n >> m;
  std::vector<int> cnt(m, 0);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int l, r, s;
    std::cin >> l >> r >> s;
    --l;
    --r;
    sum += s;    
    cnt[l] += s;
    if (r < m - 1) cnt[r + 1] -= s;
  }

  std::vector<int> tot(m, 0);
  for (int i = 0; i < m; ++i) {
    if (i > 0) tot[i] = tot[i - 1];
    tot[i] += cnt[i];
  }

  int mi = INF;
  for (int i = 0; i < m; ++i) mi = std::min(mi, tot[i]);
  std::cout << sum - mi << std::endl;
  return 0;
}
