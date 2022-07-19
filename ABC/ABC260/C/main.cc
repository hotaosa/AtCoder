#include <iostream>

using namespace std;

int main() {
  int n;
  long long x, y;
  cin >> n >> x >> y;

  long long red = 1, blue = 0;
  while (n-- > 1) {
    blue += red * x;
    red += blue;
    blue *= y;    
  }

  cout << blue << endl;
  return 0;
}