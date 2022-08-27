#include <iostream>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;

  if (a > b && a > c) swap(a, c);
  else if (b > a && b > c) swap(b, c);

  cout << (a + b >= c ? c : -1) << endl;    
  return 0;
}