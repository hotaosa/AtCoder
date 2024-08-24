#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int Mex(const vector<int> &v) {
  int ret = 0;
  while (ret < (int)size(v) && v[ret] == ret) ++ret;
  return ret;
}

int CalcGrundy(map<int, int> &grundy, int x) {
  if (grundy.contains(x)) {
    return grundy[x];
  }

  vector<int> g = {0};
  for (int y = 2; y * y <= x; ++y) {
    if (x % y == 0) {
      g.emplace_back(CalcGrundy(grundy, y));
      if (y * y != x) g.emplace_back(CalcGrundy(grundy, x / y));
    }
  }
  sort(begin(g), end(g));
  g.erase(unique(begin(g), end(g)), end(g));
  return grundy[x] = Mex(g);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;

  map<int, int> grundy;
  grundy[1] = 0;

  int xsum = 0;
  for (auto x : a) {
    xsum ^= CalcGrundy(grundy, x);
  }

  cout << (xsum ? "Anna" : "Bruno") << endl;
  return 0;
}