#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Grid {
 public:
  Grid(const int &height, const int &width) : height_(height), width_(width) { }
  int To1d(const int &row, const int &column) const { return row * width_ + column; }
  pair<int, int> To2d(const int &v) const { return make_pair(v / width_, v % width_); }

 private:
  int height_, width_;
};

map<vector<int>, int> Search(const vector<int> &s, const vector<vector<pair<int, int> > > &swap_lists) {
  map<vector<int>, int> mp;
  mp[s] = 0;
  queue<vector<int> > que;
  que.emplace(s);
  while (!que.empty()) {
    auto v = que.front();
    que.pop();
    int dist = mp[v];
    if (dist == 10) break;
    for (const auto &swap_list : swap_lists) {
      auto nv = v;
      for (auto [x, y] : swap_list) {
        nv[x] = v[y];
      }
      if (!mp.count(nv)) {
        mp[nv] = dist + 1;
        que.emplace(nv);
      }
    }
  }
  return mp;
}

int main() {
  int h, w;
  cin >> h >> w;
  const int n = h * w;
  Grid grid(h, w);
  vector<int> s(n), t(n);
  for (auto &e : s) { cin >> e; --e; }
  iota(t.begin(), t.end(), 0);

  vector<vector<pair<int, int> > > swap_lists;
  for (int sr = 0; sr < 2; ++sr) {
    for (int sc = 0; sc < 2; ++sc) {
      vector<pair<int, int> > swap_list;
      for (int r = sr; r < h - 1 + sr; ++r) {
        for (int c = sc; c < w - 1 + sc; ++c) {
          swap_list.emplace_back(grid.To1d(r, c), grid.To1d(sr + sr + h - 2 - r, sc + sc + w - 2 - c));
        }
      }
      swap_lists.emplace_back(swap_list);
    }
  }

  auto mp1 = Search(s, swap_lists);
  auto mp2 = Search(t, swap_lists);

  int res = 30;
  for (auto m : mp1) {
    if (mp2.count(m.first)) {
      res = min(res, m.second + mp2[m.first]);
    }
  }
  cout << (res < 30 ? res : -1) << endl;

  return 0;
}