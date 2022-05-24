#include <iostream>

// variable template
template<typename T> 
constexpr T pi = T{3.141592653589793238462643383L}; // (Almost) from std::numbers::pi

int addInt(int a, int b) {
    return a + b;
}

double addDouble(double a, double b) {
    return a + b;
}

double addThreeDouble(double a, double b, double c) {
    return a + b + c;
}

// general function for adding an arbitrary number of inputs
template<typename T, typename... Args>
T add(Args... summands) {
    return (... * summands);
}

int main() {
    std::cout << add<int>(1, 4, 6, 7, 8, 9) << std::endl;
    std::cout << add<float>(1.4f, 9.5f) << std::endl;

    // successfull execution
    return 0;
}