#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> rev(n);
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    rev[--p] = i;
  }

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << (rev[a - 1] < rev[b - 1] ? a : b) << endl;
  }

  return 0;
}