#include <iostream>
#include <format>

using namespace std;

void conditionals() {

    int x {8};
    int y {9};

    if (x - y == -1) {

        cout << format("x minus y is -1\n");
    }

    int new_val = (x < y) ? 0 : x;
    cout << format("New value is {}\n", new_val);
}

void pointers() {

    int x {7};
    int y {42};
    int* ip = &x;

    cout << format("The value of x is {}\n", x);
    cout << format("The value of y is {}\n", y);
    cout << format("The value of *ip is {}\n", *ip);

    ip = &y;

    cout << format("The value of *ip is {}\n", *ip);
}

void definingVariables() {

    int i {47};
    cout << format("i is {}\n", i);
}

void statement() {

    int x;
    x = 42;

    auto str = format("x is {}\n", x);
    cout << str;
}

int main() {

    const char * str {" 2025 "};
    cout << format("C++ Essential Training{}\n", str);

    statement();
    definingVariables();
    pointers();
    conditionals();
}

