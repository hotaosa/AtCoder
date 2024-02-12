#include <deque>
#include <iostream>

using namespace std;

int main() {
  int q;
  cin >> q;
  deque<int> dq;
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      dq.emplace_front(x);
    } else {
      cout << dq[--x] << endl;
    }
  }
  return 0;
}
