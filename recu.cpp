#include <iostream>
#include <cmath> // For the pow function
#include <vector>


int x, n, cnt;
void solve(int i, int sum) {
    if (i == 50) {
        if (sum == x)
            cnt++;
        return;
    }
    if (sum + std::pow(i, n) <= x)
        solve(i + 1, sum + std::pow(i, n));
    solve(i + 1, sum);
    std::cout << "test" << std::endl;
}

int main() {
    cnt = 0;
    std::cin >> x >> n;
    solve(1, 0);
    std::cout << "Count: " << cnt << std::endl;
    return 0;
}
