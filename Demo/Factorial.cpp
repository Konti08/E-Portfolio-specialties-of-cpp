#include <iostream>

// metaprogramming determine result at compile time
template <int N>
struct Factorial {
    static int const value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<1> {
    static int const value = 1;
};

// iterative programming will determine the result at run time
int factorial(int n) {
    int result = 1;
    for(int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::cout << Factorial<4>::value << std::endl;
    std::cout << factorial(4) << std::endl;

    // successfull execution
    return 0;
}