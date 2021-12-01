#include <bits/stdc++.h>
#include <atcoder/all>

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
    int n;
    std::cin >> n;

    int res = 0, ma_a = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        if (chmax(ma_a, a)) res = b + a;
    }

    std::cout << res << std::endl;
    return 0;
}
