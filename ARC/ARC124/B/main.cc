#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::multiset<int> b;
    for (auto &p : a) std::cin >> p;
    for (int i = 0; i < n; ++i) {
        int bi;
        std::cin >> bi;
        b.insert(bi);
    }

    std::set<int> res;
    for (auto iter = b.begin(); iter != b.end(); ++iter) {
        std::multiset<int> b_copy = b;
        int x = a[0] ^ *iter;
        b_copy.erase(b_copy.find(*iter));
        bool is_good = true;        
        for (int i = 1; i < n && is_good; ++i) {
            int bi = x ^ a[i];
            auto p = b_copy.find(bi);
            if (p == b_copy.end()) is_good = false;
            else b_copy.erase(p);
        }
        if (is_good) res.insert(x);
    }

    std::cout << res.size() << std::endl;
    for (auto &p : res) std::cout << p << std::endl;
    return 0;
}
