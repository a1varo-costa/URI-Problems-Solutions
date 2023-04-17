#include <iostream>

int fib(int x) {
    int cache[3];
    cache[0] = 0;
    cache[1] = 1;

    for (int i = 2; i <= x; i++) {
        cache[i % 3] = cache[(i - 1) % 3] + cache[(i - 2) % 3];
    }

    return cache[x % 3];
}

int calls(int x) {
    return 2 * fib(x + 1) - 1;
}

int main() {
    int cases, x;

    std::cin >> cases;

    while (cases > 0) {
        std::cin >> x;
        std::cout << "fib(" << x << ") = " << calls(x) - 1 << " calls = " << fib(x) << "\n";
        cases--;
    }
    return 0;
}