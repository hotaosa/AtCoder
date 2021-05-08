#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  const long long MOD = 1000000007LL;
  int h, w;
  std::cin >> h >> w;
  int k = 0;
  std::vector<std::vector<bool> > messy(h, std::vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < w; ++j) {
      if (s[j] == '#') messy[i][j] = true;
      else ++k;
    }
  }

  std::vector<std::vector<long long> > left(h, std::vector<long long>(w, 0LL));
  std::vector<std::vector<long long> > right(h, std::vector<long long>(w, 0LL));
  std::vector<std::vector<long long> > up(h, std::vector<long long>(w, 0LL));
  std::vector<std::vector<long long> > down(h, std::vector<long long>(w, 0LL));

  for (int i = 0; i < h; ++i) {
    long long cnt = 0;
    for (int j = 1; j < w; ++j) {
      if (messy[i][j - 1]) cnt = 0;
      else ++cnt;
      left[i][j] = cnt;
    }
  }

  for (int i = 0; i < h; ++i) {
    long long cnt = 0;
    for (int j = w - 2; j >= 0; --j) {
      if (messy[i][j + 1]) cnt = 0;
      else ++cnt;
      right[i][j] = cnt;
    }
  }

  for (int j = 0; j < w; ++j) {
    long long cnt = 0;
    for (int i = 1; i < h; ++i) {
      if (messy[i - 1][j]) cnt = 0;
      else ++cnt;
      up[i][j] = cnt;
    }
  }

  for (int j = 0; j < w; ++j) {
    long long cnt = 0;
    for (int i = h - 2; i >= 0; --i) {
      if (messy[i + 1][j]) cnt = 0;
      else ++cnt;
      down[i][j] = cnt;
    }
  }


  long long res = 0LL;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (messy[i][j]) continue;
      int num = left[i][j] + right[i][j] + up[i][j] + down[i][j] + 1;
      res += modpow(2, k, MOD) - modpow(2, k - num, MOD);
      while (res < 0) res += MOD;
      res %= MOD;
    }
  }
  std::cout << res << std::endl;
  return 0;
}
