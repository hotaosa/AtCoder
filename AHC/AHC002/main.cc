#include <bits/stdc++.h>

using namespace std;

class Timer {
 public:
  Timer(const double time_limit) : time_limit_(time_limit), time_start_(chrono::system_clock::now()) { }
  inline bool Exceeded() { return ElapsedTime() > time_limit_; }

 private:
  const double time_limit_;
  const chrono::system_clock::time_point time_start_;
  inline double ElapsedTime() {
    auto time_now = chrono::system_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(time_now - time_start_).count();
  }
};

class XorShift {
 public:
  XorShift() : x_(123456789), y_(362436069), z_(521288629), w_(88675123), t_(1) { }
  int Rand() {
    t_ = x_ ^ (x_ << 11);
    x_ = y_; y_ = z_; z_ = w_;
    w_ = (w_ ^ (w_ >> 19)) ^ (t_ ^ (t_ >> 8));
    return w_ & ((1 << 30) - 1);
  }
  int Rand(const int &lb, const int &ub) {
    return Rand() % (ub - lb) + lb;
  }
  double RandDouble() {
    return (double)Rand() / ((1 << 30) - 1);
  }

 private:
  unsigned int x_, y_, z_, w_, t_;  
};

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  Timer timer(1990);
  XorShift random;

  int tile[50][50];
  int point[50][50];
  int sr, sc;
  cin >> sr >> sc;
  int m = 0;
  for (int i = 0; i < 50; ++i) for (int j = 0; j < 50; ++j) { cin >> tile[i][j]; m = max(m, tile[i][j] + 1); }
  for (int i = 0; i < 50; ++i) for (int j = 0; j < 50; ++j) cin >> point[i][j];

  vector<bool> used(m);
  for (int i = 0; i < m; ++i) used[i] = false;  

  int dr[] = {1, 0, -1, 0};
  int dc[] = {0, 1, 0, -1};
  char add[] = {'D', 'R', 'U', 'L'};
  string res = "", cur = "";
  int score_max = 0, score_cur = 0;

  auto shuffle = [&](int r, int c) -> vector<int> {
    vector<pair<int, int> > pa(4);
    pa[0] = {49 - r, 0};
    pa[1] = {c, 1};
    pa[2] = {r, 2};
    pa[3] = {49 - c, 3};
    sort(pa.begin(), pa.end());
    vector<int> order(4);
    for (int i = 0; i < 4; ++i) order[i] = pa[i].second;
    return order;
  };

  auto dfs = [&](auto dfs, int r, int c, int dir) -> void {
    if (timer.Exceeded()) {
      cout << res << endl;
      exit(0);
    }
    if (dir != -1) cur += add[dir];
    used[tile[r][c]] = true;
    score_cur += point[r][c];
    if (chmax(score_max, score_cur)) res = cur;
    auto order = shuffle(r, c);
    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[order[i]];
      int nc = c + dc[order[i]];
      if (nr < 0 || nr > 49 || nc < 0 || nc > 49 || used[tile[nr][nc]]) continue;
      dfs(dfs, nr, nc, order[i]);
    }
    score_cur -= point[r][c];
    used[tile[r][c]] = false;
    if (dir != -1) cur.pop_back();
  };

  dfs(dfs, sr, sc, -1);
  cout << res << endl;
  return 0;
}
