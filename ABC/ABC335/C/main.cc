#include <deque>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  deque<pair<int, int> > dq;
  for (int i = 1; i <= n; ++i) dq.emplace_back(i, 0);

  map<char, int> dx = {{'R', 1}, {'L', -1}, {'U', 0}, {'D', 0}};
  map<char, int> dy = {{'R', 0}, {'L', 0}, {'U', 1}, {'D', -1}};

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      char c;
      cin >> c;
      dq.pop_back();
      auto [x, y] = dq.front();
      dq.emplace_front(x + dx[c], y + dy[c]);
    } else {
      int p;
      cin >> p;
      auto [x, y] = dq[--p];
      cout << x << " " << y << endl;
    }
  }

  return 0;
}