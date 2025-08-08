#include <iostream>
#include <format>

using namespace std;


void datatypes() {

    int signed_type = -23423;
    unsigned int unsigned_type = 3243243289;

    cout << format("Signed types use 2's completment {}\n", signed_type);
    cout << format("Unsigned types remove the negative range in favor of expanding the positive range {}\n", unsigned_type);

    struct structure {
        int x;
        float b;
        char c[25];
    };

    // All variables in the union exist in the same space in memory.
    // Each assignment overwrites the previous assignment.
    union union_overlapping_objects {
        int x;
        float b;
        char c[25];
    };

    enum Color {red, green, blue};
    Color color = red;

    cout << format("Color is {}\n", static_cast<int>(color));
}


void forloops() {

    int array[] { 2, 3, 4, 5, 6};

    // C for loop
    for (int i {0}; i < 5; i++) {
        cout << format("element {} is {}\n", i, array[i]);
    }

    // take advantage of the null terminator
    const char string[] {"How now brown cow."};

    for (int i {0}; string[i]; i ++) {
        cout << format("char at {} is {}\n", i, string[i]);
    }

    // pointer loop with dereferencing
    for (auto* p = string; *p; p++) {
        cout << format("char is {}\n", *p);
    }

    // range for loop C++
    for (const int& e : array) {
        cout << format("element is {}\n", e);
    }
}


void loops() {

    int array[] { 2, 3, 4, 5, 6};
    int i {0};

    while (i < 5) {
        cout << format("element {} is {}\n", i, array[i]);
        ++i;
    }
}

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
    loops();
    forloops();
    datatypes();
}

