#include <iostream>
#include <vector>

int main() {
  constexpr long long MOD = 998244353LL;
  
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > rev(n, std::vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    int t;
    std::cin >> t;
    for (int j = 0; j < t; ++j) {
      int a;
      std::cin >> a;
      rev[i][--a] = 1;
    }
  }

  std::vector<int> s(m);
  for (int i = 0; i < m; ++i) std::cin >> s[i];

  int pos = 0;
  for (int i = 0; i < m; ++i) {
    bool found = false;
    for (int j = pos; j < n && !found; ++j) {
      if (rev[j][i] == 1) {
        if (j > pos) std::swap(rev[j], rev[pos]);
        found = true;
      }
    }
    if (found) {
      for (int j = 0; j < n; ++j) {
        if (j != pos && rev[j][i] == 1) {
          for (int k = i; k < m; ++k) rev[j][k] ^= rev[pos][k];
        }
      }
      if (s[i] == 1) for (int j = i; j < m; ++j) s[j] ^= rev[pos][j];
      ++pos;
    }
  }
  for (int i = 0; i < m; ++i) if (s[i]) { std::cout << "0" << std::endl; return 0; }

  long long res = 1LL;
  for (int i = pos; i < n; ++i) res = res * 2LL % MOD;
  std::cout << res << std::endl;
  return 0;
}
