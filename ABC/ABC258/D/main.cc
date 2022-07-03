#include <iostream>

using namespace std;

int main() {
  int n;
  long long x;
  cin >> n >> x;

  long long res = 1LL << 60, sum = 0;

  for (int i = 0; i < n && x; ++i) {
    long long a, b;
    cin >> a >> b;
    sum += a + b;    
    res = min(res, sum + b * --x);
  }
  cout << res << endl;
  return 0;
}