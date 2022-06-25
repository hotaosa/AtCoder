#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  char c = 'A';
  while (x - n > 0) {
    x -= n;
    ++c;
  }

  cout << c << endl;
  return 0;
}