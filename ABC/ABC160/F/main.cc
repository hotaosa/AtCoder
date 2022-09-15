#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

template <class sum_t, class key_t>
class ReRooting {
 public:
  struct Edge {
    int to;
    key_t data;
    sum_t dp, ndp;
    Edge(int to, key_t data, sum_t dp, sum_t ndp)
    : to(to), data(data), dp(dp), ndp(ndp) { }
  };
  ReRooting(const int &node_count,
            const function<sum_t(sum_t, sum_t)> &merge,
            const function<sum_t(sum_t, key_t)> &operate,
            const sum_t &identity)
      : node_count_(node_count),
        identity_(identity),
        graph_(node_count),
        Merge(merge),
        Operate(operate),
        sub_dp_(node_count, identity),
        dp_(node_count, identity) { }
  void AddEdge(const int &u, const int &v, const key_t &d) {
    graph_[u].emplace_back(v, d, identity_, identity_);
    graph_[v].emplace_back(u, d, identity_, identity_);
  }
  vector<sum_t> Solve() {
    DFSSub(0, -1);
    DFSAll(0, -1, identity_);
    return dp_;
  }

 private:
  const int node_count_;
  const sum_t identity_;
  vector<vector<Edge> > graph_;
  vector<sum_t> sub_dp_, dp_;
  const function<sum_t(sum_t, sum_t)> Merge;
  const function<sum_t(sum_t, key_t)> Operate;
  void DFSSub(const int &id, const int &par) {
    for (auto e = graph_[id].begin(); e != graph_[id].end(); ++e) {
      if (e->to == par) continue;
      DFSSub(e->to, id);
      sub_dp_[id] = Merge(sub_dp_[id], Operate(sub_dp_[e->to], e->data));
    }
  }
  void DFSAll(int id, int par, const sum_t &top) {
    sum_t buff = identity_;
    for (auto e = graph_[id].begin(); e != graph_[id].end(); ++e) {
      e->ndp = buff;
      e->dp = Operate(par == e->to ? top : sub_dp_[e->to], e->data);
      buff = Merge(buff, e->dp);
    }
    dp_[id] = buff;
    buff = identity_;
    for (auto e = graph_[id].rbegin(); e != graph_[id].rend(); ++e) {
      if (e->to != par) DFSAll(e->to, id, Merge(e->ndp, buff));
      e->ndp = Merge(e->ndp, buff);
      buff = Merge(buff, e->dp);
    }
  }
};

int main() {
  int n;
  cin >> n;

  const int SIZE = n + 1;
  vector<mint> fact(SIZE), finv(SIZE);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < SIZE; ++i) fact[i] = fact[i - 1] * i;
  finv[SIZE - 1] = fact[SIZE - 1].inv();
  for (int i = SIZE - 1; i > 2; --i) finv[i - 1] = finv[i] * i;
  auto binom = [&](int n, int r) -> mint {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * finv[r] * finv[n - r];
  };

  auto merge = [&](pair<mint, int> a, pair<mint, int> b) -> pair<mint, int> {
    int se = a.second + b.second;
    mint fi = a.first * b.first * binom(se, a.second);
    return make_pair(fi, se);
  };

  auto operate = [&](pair<mint, int> a, int b) -> pair<mint, int> {
    return make_pair(a.first, a.second + 1);
  };

  ReRooting<pair<mint, int>, int> rerooting(n, merge, operate, {mint(1), 0});
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    rerooting.AddEdge(--u, --v, 1);
  }

  auto res = rerooting.Solve();
  for (auto r : res) cout << r.first.val() << endl;
  return 0;
}
