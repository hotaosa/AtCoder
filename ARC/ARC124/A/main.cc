#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<bool> determined(n, false);
    std::vector<int> cnt(n, k);
    for (int i = 0; i < k; ++i) {
        char c;
        int ki;
        std::cin >> c >> ki;        

        if (determined[--ki]) { std::cout << "0" << std::endl; return 0; }
        determined[ki] = true;
        if (c == 'L') for (int j = 0; j < ki; ++j) --cnt[j];
        else for (int j = n - 1; j > ki; --j) --cnt[j];
    }

    atcoder::modint998244353 res = 1;
    for (int i = 0; i < n; ++i) if (!determined[i]) res *= cnt[i];
    std::cout << res.val() << std::endl;
}