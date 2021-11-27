#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n, w;
    std::cin >> n >> w;

    std::vector<std::pair<long long, int> > vp(n);
    for (auto &p : vp) std::cin >> p.first >> p.second;
    std::sort(vp.begin(), vp.end(), std::greater<>());    

    long long res = 0LL;
    for (auto &p : vp) {
        long long a = p.first;
        int b = p.second;
        int add = std::min(w, b);
        res += a * add;
        w -= add;
    }

    std::cout << res << std::endl;
    return 0;
}
