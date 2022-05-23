#include <iostream>
#include <string>

// --------------
// class template
// --------------

template <typename T>
class Array
{
private:
    T *ptr;
    int size;

public:
    Array(T arr[], int s);
    ~Array();
    T operator [](int index);
    int getSize();
    void print();
};

// constructor
template <typename T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

// destructor
template <typename T>
Array<T>::~Array() {
    delete[] ptr;
    std::cout << "Destruktor called" << std::endl;
}

// [] operator
template <typename T>
T Array<T>::operator[](int index) {
    return *(ptr + index);
}


template <typename T>
int Array<T>::getSize() {
    return size;
}

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        std::cout << " " << *(ptr + i);
    std::cout << std::endl;
}

// ------------------
// end class template
// ------------------

class StringArray : public Array<std::string>
{
    public:
        StringArray(std::string arr[], int s) : Array<std::string>(arr, s) {};
        int fullSize();
};
 
int StringArray::fullSize() {
    int fullSize = 0;
    for (int i = 0; i < getSize(); i++)
        fullSize += operator[](i).size();
    return fullSize;
}


int main() {
    int a[] = {0, 1, 2, 3, 4};
    Array<int> arr1(a, 5);
    arr1.print();

    std::string b[] = {"test", "12", "xyz"};
    StringArray arr2(b, 3);
    std::cout << arr2.fullSize() << std::endl;

    // successfull execution
    return 0;
}