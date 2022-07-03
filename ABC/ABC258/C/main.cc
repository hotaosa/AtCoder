#include <iostream>
#include <string>
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint;

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;

  mint::set_mod(n);
  mint offset = 0;

  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) offset += x;
    else printf("%c\n",s[(x - 1 - offset).val()]);
  }
  return 0;
}