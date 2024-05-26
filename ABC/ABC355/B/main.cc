#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  set<int> a, b;
  for (int i = 0; i < n + m; ++i) {
    int x;
    cin >> x;
    if (i < n) a.insert(x);
    b.insert(x);
  }

  for (auto it = next(begin(b)); it != end(b); ++it) {
    if (a.count(*it) && a.count(*prev(it))) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}