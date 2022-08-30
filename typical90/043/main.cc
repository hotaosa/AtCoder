#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

int main() {
  int h, w, sr, sc, gr, gc;
  cin >> h >> w >> sr >> sc >> gr >> gc;
  int s = --sr * w + --sc;
  int g = --gr * w + --gc;

  vector<bool> is_wall(h * w, false);
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) is_wall[i * w + j] = s[j] == '#';
  }

  auto nx = [&](int v) -> vector<int> {
    vector<int> ret(4, -1);
    if (v / w > 0) ret[0] = v - w;
    if (v / w < h - 1) ret[1] = v + w;
    if (v % w > 0) ret[2] = v - 1;
    if (v % w < w - 1) ret[3] = v + 1;
    return ret;
  };

  vector<vector<int> > dist(h * w, vector<int>(4, INF));
  deque<pair<int, int> > dq;
  for (int i = 0; i < 4; ++i) {
    dist[s][i] = 0;
    dq.push_back({s, i});
  }

  while (!dq.empty()) {
    int v = dq.front().first;
    int dir = dq.front().second;
    dq.pop_front();    
    auto nx_list = nx(v);
    for (int i = 0; i < 4; ++i) {
      int nv = nx_list[i];
      if (nv == -1 || is_wall[nv]) continue;
      if (i == dir && dist[nv][i] > dist[v][dir]) {
        dist[nv][i] = dist[v][dir];
        dq.push_front({nv, i});
      }
      if (i != dir && dist[nv][i] > dist[v][dir] + 1) {
        dist[nv][i] = dist[v][dir] + 1;
        dq.push_back({nv, i});
      }
    }
  }

  int res = INF;
  for (int i = 0; i < 4; ++i) res = min(res, dist[g][i]);
  cout << res << endl;
  return 0;
}
