#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  long long a, b;
  cin >> a >> b;
  cout << mint(a).pow(b).val() << endl;
  return 0;
}
