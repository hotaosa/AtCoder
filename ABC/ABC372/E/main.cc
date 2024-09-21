#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
 public:
  explicit UnionFind(int n) : n_(n), size_(n, 1), par_(n, -1) {
    for (int i = 0; i < n; ++i) {
      top10_.emplace_back(vector<int>{i});
    }
  }
  int Root(int v) {
    if (par_[v] == -1) return v;
    return par_[v] = Root(par_[v]);
  }
  bool Same(int u, int v) { return Root(u) == Root(v); }
  bool Merge(int u, int v) {
    if (Same(u, v)) return false;
    u = Root(u);
    v = Root(v);
    if (size_[u] < size_[v]) swap(u, v);

    par_[v] = u;
    size_[u] += size_[v];

    auto tu = &top10_[u];
    auto tv = &top10_[v];
    tu->insert(tu->end(), tv->begin(), tv->end());
    tv->clear();
    sort(tu->rbegin(), tu->rend());
    if (tu->size() > 10) tu->erase(tu->begin() + 10, tu->end());
    return true;
  }
  int KthNode(int root, int k) const {
    if ((int)size(top10_[root]) < k) {
      return -1;
    }
    return top10_[root][k - 1];
  }

 private:
  int n_;
  vector<int> size_;
  vector<int> par_;
  vector<vector<int>> top10_;
};

int main() {
  int n, q;
  cin >> n >> q;

  UnionFind uf(n);
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 1) {
      uf.Merge(--u, --v);
    } else {
      auto res = uf.KthNode(uf.Root(--u), v);
      cout << (res >= 0 ? res + 1 : res) << endl;
    }
  }

  return 0;
}
