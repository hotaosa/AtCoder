#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> res(n + 2, 0);
    for (int x = 1; x * x < n; ++x) {
        for (int y = 1; x * x + y * y < n; ++y) {
            for (int z = 1; x * x + y * y + z * z < n; ++z) {
                ++res[std::min(n + 1, x * x + y * y + z * z + x * y + y * z + z * x)];
            }
        }
    }

    for (int i = 1; i <= n; ++i) std::cout << res[i] << std::endl;
    return 0;
}
