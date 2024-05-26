#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  vector<set<int>> sr(n), sc(n);
  set<int> sd1, sd2;

  for (int i = 0; i < t; ++i) {
    int a;
    cin >> a;
    int r = --a / n;
    int c = a % n;
    if ((sr[r].insert(c).second && (int)size(sr[r]) == n) ||
        (sc[c].insert(r).second && (int)size(sc[c]) == n) ||
        (r == c && sd1.insert(r).second && (int)size(sd1) == n) ||
        (r == n - 1 - c && sd2.insert(r).second && (int)size(sd2) == n)) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << "-1" << endl;
  return 0;
}
