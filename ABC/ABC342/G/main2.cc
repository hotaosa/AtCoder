#include <iostream>
#include <queue>

using namespace std;

template <class T>
class RemoveablePriorityQueue {
 public:
  void Emplace(const T &val) { pque1.emplace(val); }
  void Remove(const T &val) { pque2.emplace(val); }
  T Top() {
    Update();
    return pque1.top();
  }
  void Pop() {
    Update();
    pque1.pop();
  }
  bool Empty() {
    Update();
    return pque1.empty();
  }

 private:
  void Update() {
    while (!pque1.empty() && !pque2.empty() && pque1.top() == pque2.top()) {
      pque1.pop();
      pque2.pop();
    }
  }
  priority_queue<T> pque1, pque2;
};

class Solver {
 public:
  explicit Solver(const vector<int> &v) {
    n_ = 1;
    while (n_ < (int)v.size()) n_ <<= 1;
    data_.resize(n_ * 2);
    for (int i = 0; i < n_ - 1; ++i) {
      data_[i].Emplace(0);
    }
    for (int i = 0; i < (int)v.size(); ++i) {
      data_[n_ - 1 + i].Emplace(v[i]);
    }
  }
  void ChangeMax(const int &l, const int &r, const int &val) {
    ChangeMaxSub(l, r, 0, 0, n_, val);
  }
  void Remove(const int &l, const int &r, const int &val) {
    RemoveSub(l, r, 0, 0, n_, val);
  }
  int GetVal(const int &idx) {
    int i = idx + n_ - 1;
    int ret = data_[i].Top();
    while (i > 0) {
      i = (i - 1) / 2;
      ret = max(ret, data_[i].Top());
    }
    return ret;
  }

 private:
  void ChangeMaxSub(const int &ql, const int &qr, const int &idx, const int &l,
                    const int &r, const int &val) {
    if (qr <= l || ql >= r) {
      return;
    } else if (ql <= l && qr >= r) {
      data_[idx].Emplace(val);
    } else {
      ChangeMaxSub(ql, qr, idx * 2 + 1, l, (l + r) / 2, val);
      ChangeMaxSub(ql, qr, idx * 2 + 2, (l + r) / 2, r, val);
    }
  }
  void RemoveSub(const int &ql, const int &qr, const int &idx, const int &l,
                 const int &r, const int &val) {
    if (qr <= l || ql >= r) {
      return;
    } else if (ql <= l && qr >= r) {
      data_[idx].Remove(val);
    } else {
      RemoveSub(ql, qr, idx * 2 + 1, l, (l + r) / 2, val);
      RemoveSub(ql, qr, idx * 2 + 2, (l + r) / 2, r, val);
    }
  }

  int n_;
  vector<RemoveablePriorityQueue<int> > data_;
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;

  Solver solver(a);
  int q;
  cin >> q;
  vector<int> l(q), r(q), x(q);
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      cin >> l[i] >> r[i] >> x[i];
      solver.ChangeMax(--l[i], r[i], x[i]);
    } else if (t == 2) {
      int idx;
      cin >> idx;
      --idx;
      solver.Remove(l[idx], r[idx], x[idx]);
    } else {
      int idx;
      cin >> idx;
      cout << solver.GetVal(--idx) << endl;
    }
  }

  return 0;
}
