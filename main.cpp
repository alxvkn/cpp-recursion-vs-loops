#include <chrono>
#include <iostream>

unsigned long long fact_recursive(unsigned long long n) {
    if (n == 1) return n;
    return n * fact_recursive(n - 1);
}

unsigned long long fact_loop(unsigned long long n) {
    unsigned long long ret = 1;
    while (n > 1) {
        ret *= n;
        n--;
    }
    return ret;
}

int main() {
    unsigned n = 50;
    auto start = std::chrono::steady_clock::now();

    unsigned long long f = fact_loop(n);

    auto end = std::chrono::steady_clock::now();

    std::cout
        << "loop:      "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
        << "ns "
        << f
        << std::endl;

    start = std::chrono::steady_clock::now();

    f = fact_recursive(n);

    end = std::chrono::steady_clock::now();

    std::cout
        << "recursive: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
        << "ns "
        << f
        << std::endl;
}
