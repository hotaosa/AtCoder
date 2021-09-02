#include <iostream>
#include <map>
#include <queue>

int main() {
  int n;
  long long k;
  std::cin >> n >> k;

  std::map<long long, int> ma;
  std::priority_queue<long long> pq;
  for (int i = 0; i < n; ++i) {
    long long a;
    std::cin >> a;
    if (++ma[a] == 1) pq.push(a);
  }

  auto cntup = [&](long long a, long long b) -> long long {
    return (a + b) * (a - b + 1) / 2LL;
  };

  long long res = 0LL;
  while (k) {
    if (pq.empty()) break;
    long long tp = pq.top();
    pq.pop();
    long long nx = (pq.empty() ? 0LL : pq.top());

    if ((tp - nx) * ma[tp] <= k) {
      res += cntup(tp, nx + 1) * ma[tp];
      k -= (tp - nx) * ma[tp];
      ma[nx] += ma[tp];
      ma[tp] = 0;
    } else if (ma[tp] <= k) {
      long long tp_new = tp - k / ma[tp];
      pq.push(tp_new);
      res += cntup(tp, tp_new + 1) * ma[tp];
      k -= (tp - tp_new) * ma[tp];
      ma[tp_new] += ma[tp];
      ma[tp] = 0;
    } else {
      res += tp * k;
      k = 0LL;
    }
  }

  std::cout << res << std::endl;
  return 0;  
}
