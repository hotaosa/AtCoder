#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::pair<int, int> Solve(const std::string &s, int l, int r) {
  if (r - l == 1) return {s[l] - '0', 1};
  int d = (r - l) / 3;
  std::array<std::vector<int>, 2> cnt;
  for (int i = l; i < r; i += d) {
    auto [r, c] = Solve(s, i, i + d);
    cnt[r].emplace_back(c);
  }
  int win = (std::size(cnt[0]) > std::size(cnt[1])) ? 0 : 1;
  std::sort(std::begin(cnt[win]), std::end(cnt[win]));
  int diff = std::size(cnt[win]) - std::size(cnt[win ^ 1]);
  return {win, std::accumulate(std::begin(cnt[win]),
                               std::begin(cnt[win]) + (diff + 1) / 2, 0)};
}

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;

  std::cout << Solve(s, 0, std::size(s)).second << "\n";
  return 0;
}