#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long s = 0LL, sum = 0LL;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    sum += a;
    s = max(s, -sum);
  }

  cout << s + sum << endl;
  return 0;
}