#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto &p : a) std::cin >> p;

    auto update = [&]() -> bool {
        --k;
        std::vector<int> nx(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            ++nx[std::max(0, i - a[i])];
            --nx[std::min(n, i + a[i] + 1)];
        }
        bool yet = false;
        for (int i = 0; i < n; ++i) {
            a[i] = nx[i];
            if (i > 0) a[i] += a[i - 1];
            if (a[i] < n) yet = true;
        }        
        return k && yet;
    };

    while (update()) { }

    for (auto &p : a) std::cout << p << " ";
    std::cout << std::endl;
    return 0;
}
