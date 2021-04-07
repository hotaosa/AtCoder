#include <bits/stdc++.h>

int main() {
  int h, w, k, n;
  std::cin >> h >> w >> k >> n;
  std::vector<std::pair<int, int>> candy;
  std::vector<int> r(h, 0), c(w, 0);
  for (int i = 0; i < n; ++i) {
    int rr, cc;
    std::cin >> rr >> cc;
    --rr;
    --cc;
    ++r[rr];
    ++c[cc];
    candy.push_back(std::make_pair(rr, cc));
  }

  std::vector<int> c_copy = c;
  std::sort(c_copy.begin(), c_copy.end());

  long long res = 0LL;
  for (int i = 0; i < h; ++i) {
    int diff = k - r[i];
    res += std::upper_bound(c_copy.begin(), c_copy.end(), diff)
      - std::lower_bound(c_copy.begin(), c_copy.end(), diff);
  }

  for (int i = 0; i < n; ++i) {
    if (r[candy[i].first] + c[candy[i].second] == k) --res;
    else if (r[candy[i].first] + c[candy[i].second] == k + 1) ++res;
  }

  std::cout << res << std::endl;
  return 0;  
}
