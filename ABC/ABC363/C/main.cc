#include <algorithm>
#include <iostream>

using namespace std;

bool IsPalindrome(const string &s) {
  for (int l = 0, r = size(s) - 1; l < r; ++l, --r) {
    if (s[l] != s[r]) return false;
  }
  return true;
}

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  sort(begin(s), end(s));

  int res = 0;
  do {
    bool includes_palindrome = false;
    for (int l = 0; l + k <= n; ++l) {
      includes_palindrome |= IsPalindrome(s.substr(l, k));
    }
    if (!includes_palindrome) ++res;
  } while (next_permutation(begin(s), end(s)));

  cout << res << endl;
  return 0;
}