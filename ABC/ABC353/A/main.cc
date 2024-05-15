#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto &e : h) cin >> e;

  int res = -1;
  for (int i = n - 1; i > 0; --i) {
    if (h[i] > h[0]) {
      res = i + 1;
    }
  }

  cout << res << endl;
  return 0;
}