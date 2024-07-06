#include <iostream>
#include <vector>

using namespace std;

bool Overlap(int l1, int r1, int l2, int r2) {
  if (l1 >= r2) return false;
  if (l2 >= r1) return false;
  return true;
}

int main() {
  vector<int> a(6), b(6);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  bool ol = true;
  for (int i = 0; i < 3; ++i) {
    ol &= Overlap(a[i], a[i + 3], b[i], b[i + 3]);
  }

  cout << (ol ? "Yes" : "No") << endl;
  return 0;
}