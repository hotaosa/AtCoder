#include <iostream>
//
#include <atcoder/segtree>

using namespace std;

struct ValueCount {
  int value, count;
  ValueCount() : value(0), count(0) {}
  ValueCount(int v) : value(v), count(1) {}
  bool operator<(const ValueCount &other) const {
    return make_pair(value, count) < make_pair(other.value, other.count);
  }
};

struct Node {
  ValueCount first, second;
  Node() : first(ValueCount()), second(ValueCount()) {}
  Node(ValueCount f) : first(f), second(ValueCount()) {}
  Node(ValueCount f, ValueCount s) : first(f), second(s) {}
};

Node Merge(Node a, Node b) {
  vector<ValueCount> v = {a.first, a.second, b.first, b.second};
  sort(v.rbegin(), v.rend());

  vector<ValueCount> v2 = {v[0]};
  for (int i = 1; i < (int)v.size(); ++i) {
    if (v[i].value == v2.back().value) {
      v2.back().count += v[i].count;
    } else {
      v2.emplace_back(v[i]);
    }
  }

  return Node(v2[0], v2[1]);
}

Node E() { return Node(); }

using Segtree = atcoder::segtree<Node, Merge, E>;

int main() {
  int n, q;
  cin >> n >> q;
  vector<Node> v;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    v.emplace_back(ValueCount{a});
  }

  Segtree seg(v);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, x;
      cin >> p >> x;
      seg.set(--p, Node{ValueCount{x}});
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(--l, r).second.count << endl;
    }
  }

  return 0;
}