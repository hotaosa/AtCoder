#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr int INF = 1 << 30;

struct Edge {
  int to, w;
  Edge(int to_, int w_) : to(to_), w(w_) { }    
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

vector<int> dijcstra(const vector<vector<Edge> > &graph, int s) {
  int n = graph.size();
  vector<int> dist(n, INF);
  dist[s] = 0;

  priority_queue<pair<int, int>,
                      vector<pair<int, int> >,
                      greater<pair<int, int> > > que;
  que.push(make_pair(dist[s], s));
  while (!que.empty()) {
    int v = que.top().second;
    int d = que.top().first;
    que.pop();
    if (d > dist[v]) continue;
    for (auto e : graph[v]) if (chmin(dist[e.to], dist[v] + e.w)) que.push(make_pair(dist[e.to], e.to));
  }
  return dist;
}

int main() {
  int h, w, s, g;
  cin >> h >> w;
  vector<vector<char> > maze(h, vector<char>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> maze[i][j];
      if (maze[i][j] == 'S') s = i * w + j;
      else if (maze[i][j] == 'G') g = i * w + j;
    }
  }

  int dr[] = {1, 0, -1, 0};
  int dc[] = {0, 1, 0, -1};

  vector<vector<Edge> > graph(h * w + 26);
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (maze[r][c] == '#') continue;
      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < h && nc >= 0 && nc < w && maze[nr][nc] != '#') graph[r * w + c].emplace_back(nr * w + nc, 1);        
      }
      if (maze[r][c] >= 'a' && maze[r][c] <= 'z') {
        graph[r * w + c].emplace_back(h * w + maze[r][c] - 'a', 1);
        graph[h * w + maze[r][c] - 'a'].emplace_back(r * w + c, 0);
      }
    }
  }  

  vector<int> dist = dijcstra(graph, s);
  cout << (dist[g] < INF ? dist[g] : -1) << endl;
  return 0;
}
