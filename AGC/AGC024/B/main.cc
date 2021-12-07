#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), pos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        pos[--a[i]] = i;
    }

    int res = n, cur = 0, len = 1;
    while (++cur < n) {
        if (pos[cur] > pos[cur - 1]) ++len;
        else {
            res = std::min(res, n - len);
            len = 1;
        }
    }
    res = std::min(res, n - len);
    std::cout << res << std::endl;
    return 0;
}
