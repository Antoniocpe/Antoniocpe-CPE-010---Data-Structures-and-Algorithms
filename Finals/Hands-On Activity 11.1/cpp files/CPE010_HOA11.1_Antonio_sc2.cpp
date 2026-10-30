#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>

bool isUniqueSet(const std::vector<int>& arr) {
    std::unordered_set<int> seen;

    for (int num: arr) {
        if (seen.count(num) > 0) {
            return false;
        }
        seen.insert(num);
    }
    return true;
}

void time_complex(const std::vector<int>& arr) {
    auto begin = std::chrono::steady_clock::now();
    bool result = isUniqueSet(arr);
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    
    std::cout << "Result: " << std::boolalpha << result << "\nTime taken: " << duration << " nanoseconds\n";

}

int main() {
    time_complex({1, 2, 3});
    time_complex({1, 2, 1});

    return 0;
}