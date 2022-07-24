#include <iostream>

using namespace std;

int main() {
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  cout << max(0, min(r1, r2) - max(l1, l2)) << endl;
  return 0;
}