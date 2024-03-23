#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int prev = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (i > 0) {
      cout << prev * a << " ";
    }
    prev = a;
  }
  cout << endl;

  return 0;
}