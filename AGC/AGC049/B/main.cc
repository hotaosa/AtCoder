#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    if (s == t) { std::cout << "0" << std::endl; return 0; }

    std::vector<int> p_s, p_t;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') p_s.push_back(i);
        if (t[i] == '1') p_t.push_back(i);
    }

    if (p_s.size() < p_t.size() || (p_s.size() + p_t.size()) & 1) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    for (auto ritr_s = p_s.rbegin(), ritr_t = p_t.rbegin(); ritr_t != p_t.rend(); ++ritr_s, ++ritr_t) {
        if (*ritr_s < *ritr_t) {
            std::cout << "-1" << std::endl;
            return 0;
        }
    }

    long long res = 0;
    auto itr_s = p_s.begin(), itr_t = p_t.begin();
    while (itr_t != p_t.end()) {
        if (*itr_s >= *itr_t) {
            res += *itr_s - *itr_t;
            ++itr_s;
            ++itr_t;
        } else {
            int cur = *itr_s;
            int nx = *(++itr_s);
            res += nx - cur;
            ++itr_s;
        }
    }
    while (itr_s != p_s.end()) {
        int cur = *itr_s;
        int nx = *(++itr_s);
        res += nx - cur;
        ++itr_s;
    }

    std::cout << res << std::endl;
    return 0;
}
