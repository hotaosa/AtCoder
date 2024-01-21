#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int st = 0, sa = 0;
  while (n--) {
    int x, y;
    cin >> x >> y;
    st += x;
    sa += y;
  }

  if (st > sa) {
    cout << "Takahashi\n";
  } else if (st < sa) {
    cout << "Aoki\n";
  } else {
    cout << "Draw\n";
  }

  return 0;
}