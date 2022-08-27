#include <iostream>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  bool fi = false, se = false, both = false;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    a %= x + y;
    both |= a >= max(x, y);
    fi |= a >= x && a < y;
    se |= a >= y && a < x;
  }

  if (!both && !fi) cout << "Second" << endl;
  else if (se) cout << "Second" << endl;
  else cout << "First" << endl;
  return 0;
}