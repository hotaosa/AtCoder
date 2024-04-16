#include <bit>
#include <iostream>
#include <set>
#include <vector>
//
#include <atcoder/modint>

using namespace std;
using ll = long long;

template <class T>
inline bool ChangeMin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool ChangeMax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  vector<int> a(9);
  for (auto &e : a) cin >> e;

  const vector<vector<int>> lines = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
                                     {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
                                     {0, 4, 8}, {2, 4, 6}};
  vector<int> wins;
  for (const auto &line : lines) {
    int b = 0;
    for (const auto x : line) {
      b |= 1 << x;
    }
    wins.emplace_back(b);
  }

  auto Win = [&](int b) -> bool {
    for (auto x : wins) {
      if ((b & x) == x) {
        return true;
      }
    }
    return false;
  };

  auto Score = [&](int b) -> ll {
    ll ret = 0;
    for (int i = 0; i < 9; ++i) {
      if (b >> i & 1) {
        ret += a[i];
      } else {
        ret -= a[i];
      }
    }
    return ret;
  };

  constexpr int SIZE = 1 << 9;
  constexpr ll INF = 1LL << 60;
  vector dp(SIZE, vector<ll>(SIZE, 0LL));
  auto Solve = [&](auto Solve, int bt, int ba) -> ll {
    if (dp[bt][ba]) return dp[bt][ba];
    if (Win(bt)) return dp[bt][ba] = INF;
    if (Win(ba)) return dp[bt][ba] = -INF;
    int turn = __builtin_popcount(bt) + __builtin_popcount(ba);
    if (turn == 9) {
      return dp[bt][ba] = Score(bt);
    }
    turn &= 1;
    if (turn) {
      dp[bt][ba] = INF;
      for (int i = 0; i < 9; ++i) {
        if (bt >> i & 1 || ba >> i & 1) continue;
        ChangeMin(dp[bt][ba], Solve(Solve, bt, ba | (1 << i)));
      }
    } else {
      dp[bt][ba] = -INF;
      for (int i = 0; i < 9; ++i) {
        if (bt >> i & 1 || ba >> i & 1) continue;
        ChangeMax(dp[bt][ba], Solve(Solve, bt | (1 << i), ba));
      }
    }
    return dp[bt][ba];
  };

  auto res = Solve(Solve, 0, 0);
  cout << (res > 0 ? "Takahashi" : "Aoki") << endl;
  return 0;
}