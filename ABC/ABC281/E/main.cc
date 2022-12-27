#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T>
class PrioritySum {
 public:
  PrioritySum(const int &k) : k_(k), sum_(0) { }  
  void SetK(const int &k) {
    k_ = k;
    Update();
  }
  void Insert(const T &x) {
    in_.emplace(x);
    sum_ += x;
    Update();
  }
  void Erase(const T &x) {
    if (!in_.empty() && in_.top() == x) {
      sum_ -= x;
      in_.pop();
    } else if (!in_.empty() && in_.top() > x) {
      sum_ -= x;
      d_in_.emplace(x);
    } else {
      d_out_.emplace(x);
    }
    Update();
  }
  size_t Size() const {
    return in_.size() - d_in_.size() + out_.size() + d_out_.size();
  }
  T Sum() const {
    return sum_;
  }

 private:
  size_t k_;
  T sum_;
  priority_queue<T, vector<T>, less<T> > in_, d_in_;
  priority_queue<T, vector<T>, greater<T> > out_, d_out_;

  void Update() {
    while (in_.size() - d_in_.size() < k_ && !out_.empty()) {
      auto p = out_.top();
      out_.pop();
      if (!d_out_.empty() && p == d_out_.top()) {
        d_out_.pop();
      } else {
        sum_ += p;
        in_.emplace(p);
      }
    }
    while (in_.size() - d_in_.size() > k_) {
      auto p = in_.top();
      in_.pop();
      if (!d_in_.empty() && p == d_in_.top()) {
        d_in_.pop();        
      } else {
        sum_ -= p;
        out_.emplace(p);
      }
    }
    while (!d_in_.empty() && in_.top() == d_in_.top()) {
      in_.pop();
      d_in_.pop();
    }
  }
};

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  PrioritySum<long long> ps(k);
  for (int i = 0; i < m; ++i) ps.Insert(a[i]);

  for (int i = m; i <= n; ++i) {
    ps.Erase(a[i - m]);
    ps.Insert(a[i]);
    cout << ps.Sum() << " ";
  }
  cout << endl;  
  return 0;
}
