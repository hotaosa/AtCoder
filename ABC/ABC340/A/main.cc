#include <iostream>

using namespace std;

int main() {
  int a, b, d;
  cin >> a >> b >> d;
  for (int x = a; x <= b; x += d) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}