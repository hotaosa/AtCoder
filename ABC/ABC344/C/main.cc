#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;
  int m;
  cin >> m;
  vector<int> b(m);
  for (auto &e : b) cin >> e;
  int l;
  cin >> l;
  vector<int> c(l);
  for (auto &e : c) cin >> e;

  set<int> se;
  for (int x : a) {
    for (int y : b) {
      for (int z : c) {
        se.insert(x + y + z);
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << (se.count(x) ? "Yes\n" : "No\n");
  }

  return 0;
}