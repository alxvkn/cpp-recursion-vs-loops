#include <chrono>
#include <iostream>

unsigned long long sum_recursive(unsigned long long n) {
    if (n == 1) return n;
    return n + sum_recursive(n - 1);
}

unsigned long long sum_loop(unsigned long long n) {
    unsigned long long ret = 1;
    while (n > 1) {
        ret += n;
        n--;
    }
    return ret;
}

int main() {
    unsigned n = 0xffff;
    auto start = std::chrono::steady_clock::now();

    unsigned long long s = sum_loop(n);

    auto end = std::chrono::steady_clock::now();

    std::cout
        << "loop:      "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
        << "ns "
        << s
        << std::endl;

    start = std::chrono::steady_clock::now();

    s = sum_recursive(n);

    end = std::chrono::steady_clock::now();

    std::cout
        << "recursive: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
        << "ns "
        << s
        << std::endl;
}
