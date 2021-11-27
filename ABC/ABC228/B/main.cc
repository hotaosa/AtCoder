#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n, x;
    std::cin >> n >> x;
    --x;

    std::vector<int> a(n);
    for (auto &p : a) { std::cin >> p; --p; }

    std::set<int> se;
    while (se.insert(x).second) x = a[x];

    std::cout << se.size() << std::endl;
    return 0;
}
