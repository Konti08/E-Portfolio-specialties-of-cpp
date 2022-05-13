# E-Portfolio-specialties-of-cpp
This is the repository for my e-Portfolio for software engineering course 2021/2022. The topic of this presentation were the specialities of the programming C++, especially Templates and *Metaprogramming* which is extensively used in the Standard Template Library (STL).

## Prerequisites
No other prerequisites than an internet connection are needed in order to follow this e-portfolio. While exploring the functionalities of the C++ templates we will use compiler explorer [godbolt](https://godbolt.org/). Godbolt is a web-based compiler and code explorer for C/C++, which allows us to write, compile and run C or C++ code. The main feature, however is the ability to investigate the corresponding assembly code for each line of C++ code in the browser. We will use this feature to understand the characteristics of C++ templates as simple as possible.

## Getting started
Each of the following code snippets can be compiled, investigated and executed in the browser by simply pasting the source into the code segment. All demo code snippets can be found in the [demo](/Demo/) folder. To get started with C++ Templates we will start with writing an type independent adder, which accepts an arbitrary number of parameters of the same type within 4 lines of code with zero runtime overhead. First copy the [code](/Demo/Addition.cpp) and paste it into the code segment. The important part is the where the `template` keyword is used. 

```cpp
template<typename T, typename... Args>
T add(Args... summands) {
    return (... * summands);
}
```
Also have a look at the generated assembly code and try understanding the code at least a bit. Now add another addition like this:

```cpp
std::cout << add<float>(1.4f, 9.5f, 6.9f) << std::endl;
```
Try to spot what changes in the newly generated assembly code. You will recognize that for every function call with a new number of parameters or new type the compiler generates a new function, a so called specialisation in the assembly code.
```asm
int add<int, int, int, int, int, int, int>(int, int, int, int, int, int):
        push    rbp
        ...
        ret
float add<float, float, float>(float, float):
        push    rbp
        ...
        ret
float add<float, float, float, float>(float, float, float):
        push    rbp
        ...
        ret
```
After you understood this first example you can try out all the remaining code snippets except for the *PrimeNumbers.cpp* and try to understand the underlying concepts and corresponding assmebly code.

[PrimeNumbers.cpp](/Demo/PrimeNumbers.cpp) contains probably the most famous programm that failes to compile. It was written by Erwin Unruh during a C++ convention and calculates the prime numbers up to a given number without finishing the compile process. At this time the compile tries to resolve the static call of the template but is unable to finish due to intenionally placed errors. To try out this code you need to have Unix system along with a C++ compiler installed. Then run the following command in the terminal:
```bash
g++ -std=c++03 -c -fpermissive PrimeNumbers.cpp 2>&1 | grep "In instantiation"
```
The you will be presented with a list of errors, indicating the prim numbers up to the given number:

## Presentation
The presentation for this e-Portfolio can be found [here](/Presentation/Presentation.pdf).




