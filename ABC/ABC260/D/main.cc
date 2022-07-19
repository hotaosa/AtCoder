#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  set<pair<int, int> > se;
  vector<int> nx(n, -1);
  vector<int> res(n, -1);

  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    auto p = se.lower_bound({--x, 0});

    int cnt = 1;
    if (p != se.end()) {
      cnt = p->second + 1;
      nx[x] = p->first;
      se.erase(p);
    }
    if (cnt == k) {
      while (x != -1) {
        res[x] = i;
        x = nx[x];
      }
    }
    else se.insert({x, cnt});
  }

  for (int r : res) cout << r << endl;
  return 0;
}