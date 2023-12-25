#include <cassert>
#include <iostream>
#include <set>
#include <vector>

#include <atcoder/dsu>
#include <atcoder/modint>

using mint = atcoder::modint998244353;

class Grid {
 public:
  Grid(const int &height, const int &width) : height_(height), width_(width) { }
  int To1d(const int &row, const int &column) const { return row * width_ + column; }
  std::pair<int, int> To2d(const int &v) const { return std::make_pair(v / width_, v % width_); }
  std::vector<int> Adjacents(const int &v, int dir = 4) const {
    assert(dir > 0 && dir <= 8);
    std::vector<int> ret;
    const auto [r, c] = To2d(v);
    if (c < width_ - 1) ret.emplace_back(v + 1);
    if (dir > 1 && r < height_ - 1) ret.emplace_back(v + width_);
    if (dir > 2 && c > 0) ret.emplace_back(v - 1);
    if (dir > 3 && r > 0) ret.emplace_back(v - width_);
    if (dir > 4 && r < height_ - 1 && c < width_ - 1) ret.emplace_back(v + width_ + 1);
    if (dir > 5 && r < height_ - 1 && c > 0) ret.emplace_back(v + width_ - 1);
    if (dir > 6 && r > 0 && c > 0) ret.emplace_back(v - width_ - 1);
    if (dir > 7 && r > 0 && c < width_ - 1) ret.emplace_back(v - width_ + 1);
    return ret;
  }

 private:
  int height_, width_;
};

int main() {
  int h, w;
  std::cin >> h >> w;
  const int n = h * w;
  std::string s = "";
  for (int i = 0; i < h; ++i) {
    std::string si;
    std::cin >> si;
    s += si;
  }

  Grid grid(h, w);
  atcoder::dsu uf(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '#') {
      for (int j : grid.Adjacents(i, 2)) {
        if (s[j] == '#') {
          uf.merge(i, j);
        }
      }
    }
  }

  int cnt_cc = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '#' && uf.leader(i) == i) ++cnt_cc;
  }

  mint res = 0;
  int cnt_red = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      ++cnt_red;
      std::set<int> se;
      for (int j : grid.Adjacents(i, 4)) {
        if (s[j] == '#') se.insert(uf.leader(j));
      }
      res += cnt_cc - se.size() + 1;
    }
  }
  res /= cnt_red;
  std::cout << res.val() << std::endl;

  return 0;
}