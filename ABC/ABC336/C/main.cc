#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  long long n;
  cin >> n;
  if (--n == 0) {
    cout << 0 << endl;
    return 0;
  }

  string s = "";
  while (n) {
    s += '0' + (n % 5);
    n /= 5;
  }
  reverse(s.begin(), s.end());

  for (auto c : s) cout << (c - '0') * 2;
  cout << endl;
  return 0;
}