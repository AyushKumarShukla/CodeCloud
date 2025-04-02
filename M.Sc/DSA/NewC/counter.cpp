#include <iostream>
#include <vector>

void incrementBinary(std::vector<bool>& bin) {
    int n = bin.size();
    for (int i = n - 1; i >= 0; --i) {
        bin[i] = !bin[i]; // Flip bit
        if (bin[i]) break; // Stop when we set a `1`
    }
}

void printBinary(const std::vector<bool>& bin) {
    for (bool bit : bin) std::cout << bit;
    std::cout << "\n";
}

int main() {
    std::vector<bool> binary = {0, 1, 1, 1}; // Example: 0111 (7 in decimal)

    std::cout << "Before increment: ";
    printBinary(binary);

    incrementBinary(binary);

    std::cout << "After increment:  ";
    printBinary(binary);

    return 0;
}
