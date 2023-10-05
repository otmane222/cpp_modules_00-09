#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int initialValue) : value(initialValue) {}

    // Post-increment operator
    MyClass operator++(int) {
        MyClass temp(*this); // Create a copy of the current object
        ++value;            // Update the current object
        return temp;        // Return the copy (before increment)
    }

    int getValue() const {
        return value;
    }
};

int main() {
    MyClass obj(5);

    // Use post-increment operator
    MyClass result = obj++;
    
    std::cout << "Original value: " << obj.getValue() << std::endl;    // Prints 6 (incremented)
    std::cout << "Result value: " << result.getValue() << std::endl;    // Prints 5 (before increment)

    return 0;
}