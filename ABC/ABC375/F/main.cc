#include <iostream>
#include <vector>

inline bool ChangeMin(long long &a, long long b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  std::size_t n, m, q;
  std::cin >> n >> m >> q;

  std::vector<std::size_t> a(m), b(m);
  std::vector<long long> c(m);
  for (std::size_t i = 0; i < m; ++i) {
    std::cin >> a[i] >> b[i] >> c[i];
    --a[i];
    --b[i];
  }

  std::vector<std::size_t> t(q), x(q), y(q);
  for (std::size_t i = 0; i < q; ++i) {
    std::cin >> t[i] >> x[i];
    --x[i];
    if (t[i] == 2) {
      std::cin >> y[i];
      --y[i];
    }
  }

  std::vector<bool> available(m, true);
  for (std::size_t i = 0; i < q; ++i) {
    if (t[i] == 1) available[x[i]] = false;
  }

  constexpr long long INF = 1LL << 60;
  std::vector dist(n, std::vector<long long>(n, INF));
  for (std::size_t i = 0; i < n; ++i) dist[i][i] = 0;
  for (std::size_t i = 0; i < m; ++i) {
    if (available[i]) {
      dist[a[i]][b[i]] = dist[b[i]][a[i]] = c[i];
    }
  }

  for (std::size_t k = 0; k < n; ++k) {
    for (std::size_t i = 0; i < n; ++i) {
      for (std::size_t j = 0; j < n; ++j) {
        ChangeMin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  auto AddEdge = [n, &dist, &a, &b, &c](int idx) -> void {
    bool need_update = false;
    need_update |= ChangeMin(dist[a[idx]][b[idx]], c[idx]);
    need_update |= ChangeMin(dist[b[idx]][a[idx]], c[idx]);
    if (need_update) {
      for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < n; ++j) {
          ChangeMin(dist[i][j],
                    dist[i][a[idx]] + dist[a[idx]][b[idx]] + dist[b[idx]][j]);
          ChangeMin(dist[i][j],
                    dist[i][b[idx]] + dist[b[idx]][a[idx]] + dist[a[idx]][j]);
        }
      }
    }
  };

  std::vector<long long> res;
  for (int i = (int)q - 1; i >= 0; --i) {
    if (t[i] == 1) {
      AddEdge(x[i]);
    } else {
      long long d = dist[x[i]][y[i]];
      res.emplace_back(d < INF ? d : -1);
    }
  }

  for (auto it = std::rbegin(res); it != std::rend(res); ++it) {
    std::cout << *it << "\n";
  }

  return 0;
}