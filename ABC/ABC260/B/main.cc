#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<pair<int, pair<int, int> > > scores(n, {-1, {0, 0}});
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    scores[i].first = i;
    scores[i].second.first = a;
  }
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    scores[i].second.second = b;
  }
  
  sort(scores.begin(), scores.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs.second.first != rhs.second.first) return lhs.second.first > rhs.second.first;
    else return lhs.first < rhs.first;
  });    
  sort(scores.begin() + x, scores.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs.second.second != rhs.second.second) return lhs.second.second > rhs.second.second;
    else return lhs.first < rhs.first;
  });  
  sort(scores.begin() + x + y, scores.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs.second.first + lhs.second.second != rhs.second.first + rhs.second.second) return lhs.second.first + lhs.second.second > rhs.second.first + rhs.second.second;
    else return lhs.first < rhs.first;
  });
  sort(scores.begin(), scores.begin() + x + y + z, [](const auto &lhs, const auto &rhs) {
    return lhs.first < rhs.first;
  });

  for (int i = 0; i < x + y + z; ++i) cout << scores[i].first + 1 << endl;
  return 0;
}