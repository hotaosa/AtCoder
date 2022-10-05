#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

mint sum(mint fi, mint count, mint diff) {
  mint last = fi + diff * (count - 1);
  return (fi + last) * count / 2;
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  auto func = [&](int r, int c) -> mint {
    if (min(r, c) == 0) return 0;

    mint first_row_sum = sum(1, (c + 1) / 2, 2);
    mint second_row_sum = sum(m + 2, c / 2, 2);

    mint first_row_count = (r + 1) / 2;
    mint second_row_count = r / 2;

    mint d1 = mint((c + 1) / 2) * m * 2;
    mint d2 = mint(c / 2) * m * 2;

    return sum(first_row_sum, first_row_count, d1) + sum(second_row_sum, second_row_count, d2);
  };
  
  while (q--) {
    int r1, r2, c1, c2;
    cin >> r1 >> r2 >> c1 >> c2;
    cout << (func(r2, c2) - func(r1 - 1, c2) - func(r2, c1 - 1) + func(r1 - 1, c1 - 1)).val() << endl;
  }
  
  return 0;
}
