#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> h(n);
    for (auto &p : h) std::cin >> p;

    std::vector<int> peak;
    peak.push_back(0);
    for (int i = 1; i < n - 1; ++i) {
	if ((h[i] - h[i - 1]) * (h[i + 1] - h[i]) < 0LL) peak.push_back(i);
    }
    peak.push_back(n - 1);

    if (peak.size() == 2) { std::cout << n << std::endl; return 0; }

    bool fst = h[1] > h[0];
    bool lst = h[n - 1] > h[n - 2];
    int res = 2;
    if (!fst) res = std::max(res, peak[1] - peak[0] + 1);
    for (int i = (fst ? 1 : 2); i < (int)peak.size() - 1; i += 2) res = std::max(res, peak[i + 1] - peak[i - 1] + 1);
    if (lst) res = std::max(res, peak[peak.size() - 1] - peak[peak.size() - 2] + 1);
    std::cout << res << std::endl;
    return 0;
}
