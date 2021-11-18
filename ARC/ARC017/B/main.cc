#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &p : a) std::cin >> p;

    std::vector<int> s_p;
    s_p.push_back(0);
    for (int i = 1; i < n; ++i) if (a[i] <= a[i - 1]) s_p.push_back(i);
    s_p.push_back(n);

    int res = 0;
    for (int i = 1; i < (int)s_p.size(); ++i) {
        res += std::max(s_p[i] - s_p[i - 1] - k + 1, 0);
    }

    std::cout << res << std::endl;
    return 0;
}
