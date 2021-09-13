#include <iostream>
#include <vector>

using vll = std::vector<long long>;
using vvll = std::vector<vll>;

int main() {
  const long long MOD = 1000000007LL;
  
  long long n;
  int b, k;
  std::cin >> n >> b >> k;
  
  std::vector<bool> usable(10, false);
  for (int i = 0; i < k; ++i) {
    int c;
    std::cin >> c;
    usable[c] = true;
  }

  vvll ini(b, vll(1, 0LL));
  for (int i = 0; i < 10; ++i) if (usable[i]) ++ini[i % b][0];

  vvll mat(b, vll(b, 0LL));
  for (int i = 0; i < b; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (!usable[j]) continue;
      ++mat[(i * 10 + j) % b][i];
    }
  }

  auto mul = [&](const vvll &A, const vvll &B) -> vvll{
    vvll C(A.size(), vll(B[0].size()));
    for (int i = 0; i < (int)A.size(); ++i) {
      for (int k = 0; k < (int)B.size(); ++k) {
        for (int j = 0; j < (int)B[0].size(); ++j) {
          C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        }
      }
    }
    return C;
  };

  auto pow = [&](vvll A, long long nn) -> vvll{
    vvll B((int)A.size(), vll((int)A.size()));
    for (int i = 0; i < (int)A.size(); ++i) {
      B[i][i] = 1LL;
    }
    while (nn) {
      if (nn & 1LL) B = mul(B, A);
      A = mul(A, A);
      nn >>= 1;
    }
    return B;
  };

  vvll res = mul(pow(mat, --n), ini);
  std::cout << res[0][0] << std::endl;
  return 0;  
}
