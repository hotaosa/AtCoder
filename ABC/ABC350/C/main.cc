#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[--a[i]] = i;
  }

  vector<pair<int, int>> res;
  for (int i = 0; i < n; ++i) {
    if (a[i] == i) continue;
    res.emplace_back(min(pos[i], pos[a[i]]), max(pos[i], pos[a[i]]));
    swap(pos[i], pos[a[i]]);
    swap(a[i], a[pos[a[i]]]);
  }

  cout << size(res) << endl;
  for (auto [u, v] : res) {
    cout << u + 1 << " " << v + 1 << endl;
  }
  return 0;
}