#include <iostream>

int main() {

    const int cap = 3;
    float items[cap] = {};
    float total = 0, change = 0, payment = 0;
    int i = 0;

    for(i = 0; i < cap; i++){
        std::cout << "Item " << i+1 << " price: ";
        std::cin >> items[i];

        total += items[i];
    }

    std::cout << "Total price: " << total << std::endl;
    std::cout << "Enter payment amount: ";
    std::cin >> payment;

    if (payment < total) {
        std::cout << "Payment is insufficient";
        return 0;
    }

    change = payment - total;

    std::cout << "===========================\n";
    std::cout << "    Transaction Details" << std::endl;
    std::cout << "===========================\n\n";

    for(i = 0; i < cap; i++){
        std::cout << "Item " << i+1 << "price: " << items[i] << std::endl;
    }

    std::cout << std::endl << "Total: " << total << std::endl;
    std::cout << "Payment reveived: " << payment << std::endl;
    std::cout << "Change: " << change << std::endl;


    return 0;

}