#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> res(n, 1);
  while (q--) {
    int t;
    cin >> t;
    res[--t] ^= 1;
  }
  cout << accumulate(begin(res), end(res), 0) << endl;
  return 0;
}