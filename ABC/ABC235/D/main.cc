#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

long long rotate(long long cur) {
    long long base = 1, tmp = cur;
    while (tmp) {
        base *= 10;
        tmp /= 10;
    }
    base /= 10;
    return cur / 10 + (cur % 10) * base;
}

int main() {
    constexpr int INF = 1 << 30;
    constexpr int SIZE = 1000000;
    long long a, n;
    cin >> a >> n;
    vector<int> dist(SIZE, INF);
    dist[1] = 0;
    queue<long long> que;
    que.push(1);
    while (!que.empty()) {
        long long cur = que.front();
        que.pop();
        if (cur * a < SIZE && chmin(dist[cur * a], dist[cur] + 1)) que.push(cur * a);
        if (cur > 10 && cur % 10) {
            long long nx = rotate(cur);
            if (chmin(dist[nx], dist[cur] + 1)) que.push(nx);
        }
    }
    cout << (dist[n] < INF ? dist[n] : -1) << endl;
    return 0;
}
