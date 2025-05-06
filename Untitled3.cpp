#include <iostream>
using namespace std;

long long decimalToBinary(int n) {
    long long binary = 0;
    int place = 1; // Position multiplier (1, 10, 100, ...)
    
    while (n > 0) {
        int remainder = n % 2;
        binary += remainder * place;
        n /= 2;
        place *= 10;
    }
    return binary;
}

int main() {
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;
    cout << "Binary equivalent: " << decimalToBinary(num) << endl;
    return 0;
}
