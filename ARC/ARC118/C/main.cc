#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;

    if (n == 3) { std::cout << "6 10 15" << std::endl; return 0; }

    std::set<int> se;
    int base = 6;
    for (int i = 1; base * i <= 10000; ++i) se.insert(base * i);
    base = 10;
    for (int i = 1; base * i <= 10000; ++i) se.insert(base * i);
    base = 15;
    for (int i = 1; base * i <= 10000; ++i) se.insert(base * i);

    int cnt = 0;
    for (auto &p : se) {
        std::cout << p;
        if (++cnt < n) std::cout << " ";
        else { std::cout << std::endl; break; }
    }
    return 0;
}
