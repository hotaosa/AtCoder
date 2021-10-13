#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int> > hand(2 * n, std::vector<int>(m));
  for (int i = 0; i < 2 * n; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'G') hand[i][j] = 0;
      else if (s[j] == 'C') hand[i][j] = 1;
      else hand[i][j] = 2;
    }
  }

  auto win = [&](int i, int j, int r) -> bool{
    return (hand[i][r] - hand[j][r] == -1 || hand[i][r] - hand[j][r] == 2);
  };

  std::vector<std::pair<int, int> > vp(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    vp[i].first = 0;
    vp[i].second = i;    
  }

  for (int round = 0; round < m; ++round) {
    for (int i = 0; i < n; ++i) {
      int id1 = vp[i * 2].second;
      int id2 = vp[i * 2 + 1].second;
      if (win(id1, id2, round)) --vp[i * 2].first;
      else if (win(id2, id1, round)) --vp[i * 2 + 1].first;
    }
    std::sort(vp.begin(), vp.end());
  }

  for (int i = 0; i < 2 * n; ++i) std::cout << vp[i].second + 1 << std::endl;
  return 0;
}
