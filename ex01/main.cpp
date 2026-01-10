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

uint32_t multiplier(uint32_t a, uint32_t b) {

    uint32_t result = 0;

    while(b) {
        if ((b & 1) == 1)
            result = adder(result, a);
        a = a << 1;
        b = b >> 1;
    }

    return result;

}

int main() {

    cout << "2 * 3 = " << multiplier(2, 3) << endl;
    cout << "4 * 5 = " << multiplier(4, 5) << endl;
    cout << "7 * 8 = " << multiplier(7, 8) << endl;
    
    cout << "0 * 5 = " << multiplier(0, 5) << endl;
    cout << "5 * 0 = " << multiplier(5, 0) << endl;
    cout << "0 * 0 = " << multiplier(0, 0) << endl;
    
    cout << "1 * 42 = " << multiplier(1, 42) << endl;
    cout << "42 * 1 = " << multiplier(42, 1) << endl;
    
    cout << "8 * 16 = " << multiplier(8, 16)<< endl;
    cout << "256 * 256 = " << multiplier(256, 256) << endl;
    
    cout << "123 * 456 = " << multiplier(123, 456) << endl;
    cout << "456 * 123 = " << multiplier(456, 123) << endl;
    
    cout << "65535 * 65535 = " << multiplier(65535, 65535) << endl;
    
    return 0;
}