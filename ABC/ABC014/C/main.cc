#include <iostream>
#include <vector>

int main() {
  const int SIZ = 1000001;
  int n;
  std::cin >> n;
  std::vector<int> cnt(SIZ, 0);
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    ++cnt[a];
    if (b < SIZ) --cnt[++b];
  }

  std::vector<int> tot(SIZ, 0);
  for (int i = 0; i < SIZ; ++i) {
    if (i > 0) tot[i] = tot[i - 1];
    tot[i] += cnt[i];
  }

  int res = 0;
  for (int i = 0; i < SIZ; ++i) res = std::max(res, tot[i]);
  std::cout << res << std::endl;
  return 0;  
}
