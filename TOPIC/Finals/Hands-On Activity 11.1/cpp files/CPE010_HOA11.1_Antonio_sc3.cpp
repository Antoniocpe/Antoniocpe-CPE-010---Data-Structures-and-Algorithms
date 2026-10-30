#include <iostream>
#include <chrono>

long long rpower (int x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n-1);
}

long long brpower(int x, int n) {
    if (n == 0) return 1; 
    if (n % 2 != 0) {
        long long y = brpower(x, (n-1) /2);
        return x * y * y;
    } else {
        long long y = brpower(x, n/2);
        return y*y;
    }
}

void test_rpower(int x, int n) {
    auto begin = std::chrono::steady_clock::now();
    long long result = rpower(x, n);
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    
    std::cout << "rpower(" << x << ", " << n << "| Time: " << duration << " nanoseconds | Result: " << result << std::endl;
}

void test_brpower(int x, int n) {
    auto begin = std::chrono::steady_clock::now();
    long long result = brpower(x, n);
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "brpower(" << x << ", " << n << "| Time: " << duration << " nanoseconds | Result: " << result << std::endl;

}

int main() {

    test_rpower(1, 1000);
    test_rpower(1, 100000);
    test_brpower(1, 1000);
    test_brpower(1, 100000);

    return 0;
}