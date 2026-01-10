#include <iostream>

using namespace std;

uint32_t gray_code(uint32_t n) {

    uint32_t result = n ^ (n >> 1);
    return result;
}

int main() {

    cout << "gray_code(0) = " << gray_code(0) << endl;
    cout << "gray_code(1) = " << gray_code(1) << endl;
    cout << "gray_code(2) = " << gray_code(2) << endl;
    cout << "gray_code(3) = " << gray_code(3) << endl;
    cout << "gray_code(4) = " << gray_code(4) << endl;
    cout << "gray_code(5) = " << gray_code(5) << endl;
    cout << "gray_code(6) = " << gray_code(6) << endl;
    cout << "gray_code(7) = " << gray_code(7) << endl;

    return 0;
}