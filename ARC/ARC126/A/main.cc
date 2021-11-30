#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long n2, n3, n4;
        std::cin >> n2 >> n3 >> n4;
        
        long long res = 0LL;
        
        res += std::min(n3 / 2LL, n4);
        n3 -= res * 2LL;
        n4 -= res;

        if (n3 > 1) {
            long long add = std::min(n3 / 2LL, n2 / 2LL);
            res += add;
            n2 -= add * 2LL;
        }

        long long add = std::min(n2, n4 / 2LL);
        res += add;
        n4 -= add * 2LL;
        n2 -= add;

        add = std::min(n2 / 3LL, n4);
        res += add;
        n2 -= add * 3LL;
        res += n2 / 5LL;

        std::cout << res << std::endl;
    }        
    return 0;
}
