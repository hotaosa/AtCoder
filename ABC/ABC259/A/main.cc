#include <iostream>

using namespace std;

int main() {
  int n, m, x, t, d;
  cin >> n >> m >> x >> t >> d;
  cout << t - max(0, (x - m) * d) << endl;
  return 0;
}