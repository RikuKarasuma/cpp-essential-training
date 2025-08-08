#include <iostream>
#include <format>
#include <vector>
#include <cstdint>


using namespace std;

/**
 * Another way of using alias is 
 * using points_t = uint32_t
 * using rank_t = uint64_t;
 */
typedef uint32_t points_t;
typedef uint64_t rank_t;

struct score {

    points_t p {};
    rank_t r {};
};

void typeAlias() {

    // Alias are used to alias another type.
    const score s {5, 1};

    cout << format("Score s had {} points and a rank of {}\n", s.p, s.r);
}

void qualifiers() {

    // Immutable, static storage
    const static int i {42};

    /**
     * Two types of qualifiers in C++
     *
     * CV Qualifiers (Constant & Volatile)
     * 
     * const -- Immutable.
     * 
     * mutable -- Makes mutable from a const qualified member function.
     * (deprecated)
     * 
     * volatile -- Marks a variable that may be changed by another process. 
     *
     * Stoage Duration (Duration or Lifetime of a variable)
     * 
     * Defaultly most variables within a block use automatic lifetime, living until
     * the end of the block.
     *
     * static -- Live for the duration of the program, automatic lifetime ignored. 
     * Stored in static memory space, i.e not heap memory.
     * By default a variable defined outside a block is static.
     * 
     * register -- Variables that live on the processor register, this can make 
     * them faster and easier to access. Take as a suggestion by the compiler.
     * The compiler may or may not store the variable in a register.
     * 
     * extern -- Defined in a separate translation unit and linked in the linker
     * step. 
    */
}

void autoTypes() {

    std::string s {"This is a string"};
    auto x = s;

    cout << format("The value of x is {}\n", x);
    cout << format("The type of x is {}\n", typeid(x).name());

    // auto is very strongly typed and can't be uninitalized.
    // Can't type narrow using {}, must be initialized using =.

    std::vector<int> int_vector { 5, 4, 3, 2, 1};

    for (std::vector<int>::iterator it = int_vector.begin(); it != int_vector.end(); it ++) {

        cout << format("int is {}\n", *it);
        cout << format("type of it is {}\n", typeid(it).name());
    }
}

void floatingPointTypes() {

    const size_t byte {8};

    // Precision to 7 digits.
    // On most systems 32 bits.
    float f {};

    // Precision to 16 digits.
    // On most systems 64 bits.
    double df {};

    // May be the same as a double or a IEEE long double
    // May be 64, 80 or 128 bits depending on arch.
    long double ldf {};

    cout << format("The size of the float f is {}\n", sizeof(f) * byte);
    cout << format("The size of the dpuble df is {}\n", sizeof(df) * byte);
    cout << format("The size of the long double ldf is {}\n", sizeof(ldf) * byte);

    // Scale is how large or small a number can be.
    // Precision is accuracy of the representation to the number of digits. 
    // i.e potential rounding errors.
    // Never use floating types for accounting. Always default to integers or 
    // integer based encapsulations.
}

void integerTypes() {

    // Minimum size to contain a character.
    // On most systems it's 8 bits.
    // It may be signed or unsigned.
    char a = 'a';

    cout << format("The value of the char is {}\n", static_cast<int>(a));

    // Smallest integer type.
    // Usually 16 bits, depending on the processor arch.
    short b = 16000;

    cout << format("The value of the char is {}\n", b);

    // Natural size of an integer.
    // On most systems it is 32 bits.
    int c = 100000;

    cout << format("The value of the char is {}\n", c);

    // At least the size of an int.
    // Often double the size of an int.
    // On most systems it's either 32 or 64 bits.
    long d = 1000000000;

    cout << format("The value of the char is {}\n", d);

    // At least the size of a long int.
    // It may be double the size of a long int.
    // On most systems it's either 32 or 64 bits.
    long long e = 10000000000000;

    cout << format("The value of the char is {}\n", e);
}


void dataTypes() {

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


void forLoops() {

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
    forLoops();
    dataTypes();
    integerTypes();
    floatingPointTypes();
    autoTypes();
    qualifiers();
    typeAlias();
}

