#include <iostream>

using namespace std;


uint32_t adder(uint32_t a, uint32_t b) {

    uint32_t sum = a;
    uint32_t carry = b;

    while (b) {
        sum = a ^ b;
        carry = a & b;
        a = sum;
        b = carry << 1;
    }

    return sum;
}

int main() {
    cout << "0 + 0 = " << adder(0, 0) << endl;
    cout << "0 + 5 = " << adder(0, 5) << endl;
    cout << "5 + 0 = " << adder(5, 0) << endl;

    cout << "1 + 1 = " << adder(1, 1) << endl;
    cout << "5 + 3 = " << adder(5, 3) << endl;
    cout << "42 + 17 = " << adder(42, 17) << endl;

    cout << "8 + 8 = " << adder(8, 8) << endl;
    cout << "256 + 256 = " << adder(256, 256) << endl;

    cout << "1000 + 2000 = " << adder(1000, 2000) << endl;
    cout << "123456 + 654321 = " << adder(123456, 654321) << endl;

    cout << "4294967295 + 0 = " << adder(4294967295U, 0) << " (expected: 4294967295)" << endl;
    cout << "1 + 4294967295 = " << adder(1, 4294967295U) << " (expected: 0, overflow)" << endl;

    return 0;
}