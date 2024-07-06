#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (auto &e : a) cin >> e;
  a.insert(begin(a) + k, x);
  for (const auto &e : a) cout << e << " ";
  cout << endl;
  return 0;
}