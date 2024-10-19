#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

template <class T, class Comparator = std::greater<T>>
class PrioritySum {
 public:
  explicit PrioritySum(std::size_t k) : k_(k), sum_() {}

  void SetK(int k) {
    k_ = k;
    Update();
  }

  void Insert(const T& x) {
    in_.emplace(x);
    sum_ += x;
    Update();
  }

  void Erase(const T& x) {
    if (!in_.empty() && in_.top() == x) {
      sum_ -= x;
      in_.pop();
    } else if (!in_.empty() && ReverseComparator(in_.top(), x)) {
      sum_ -= x;
      d_in_.emplace(x);
    } else {
      d_out_.emplace(x);
    }
    Update();
  }

  T Sum() const { return sum_; }

 private:
  struct ReverseComparator {
    bool operator()(const T& lhs, const T& rhs) const {
      return Comparator{}(rhs, lhs);
    }
  };
  void Update() {
    while (!std::empty(out_) && std::size(in_) - std::size(d_in_) < k_) {
      const T p = out_.top();
      out_.pop();
      if (!std::empty(d_out_) && p == d_out_.top()) {
        d_out_.pop();
      } else {
        sum_ += p;
        in_.emplace(p);
      }
    }
    while (std::size(in_) - std::size(d_in_) > k_) {
      const T p = in_.top();
      in_.pop();
      if (!std::empty(d_in_) && p == d_in_.top()) {
        d_in_.pop();
      } else {
        sum_ -= p;
        out_.emplace(p);
      }
    }
    while (!std::empty(d_in_) && in_.top() == d_in_.top()) {
      in_.pop();
      d_in_.pop();
    }
  }

  std::size_t k_;
  T sum_;
  std::priority_queue<T, std::vector<T>, Comparator> in_;
  std::priority_queue<T, std::vector<T>, Comparator> d_in_;
  std::priority_queue<T, std::vector<T>, ReverseComparator> out_;
  std::priority_queue<T, std::vector<T>, ReverseComparator> d_out_;
};

long long Solve() {
  int n, k;
  std::cin >> n >> k;
  PrioritySum<long long, std::less<long long>> psum(k);

  std::vector<long long> a(n), b(n);
  for (auto& e : a) std::cin >> e;
  for (auto& e : b) std::cin >> e;

  std::vector<int> order(n);
  std::iota(std::begin(order), std::end(order), 0);
  std::sort(std::begin(order), std::end(order),
            [&](int i, int j) { return a[i] < a[j]; });

  long long res = 1LL << 60;
  for (int i = 0; i < n; ++i) {
    psum.Insert(b[order[i]]);
    if (i >= k - 1) {
      res = std::min(res, a[order[i]] * psum.Sum());
    }
  }
  return res;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << Solve() << "\n";
  }
  return 0;
}
