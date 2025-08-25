#include <iostream>
#include <format>
#include <vector>
#include <cstdint>
#include <string>

using namespace std;

const string UNKNOWN {"Unknown"};
const string CLONE_PREFIX {"Clone-"};

class Animal {
    string type {};
    string name {};
    string sound {};
    public:
        Animal();
        Animal(const string& type, const string& name, const string& sound);
        Animal(const Animal&); // copy constructor.
        ~Animal(); // destructor.
        Animal& operator = (const Animal&); // copy by assignment operator.
        void print() const;
};

Animal::Animal() : type(UNKNOWN), name(UNKNOWN), sound(UNKNOWN) {
    cout << "Default constructor\n";
}

Animal::Animal(const string& type, const string& name, const string& sound) 
    : type(type), name(name), sound(sound) {

    cout << "Constructor with args\n";
}


Animal::Animal(const Animal& copy) {

    cout << "Copy constructor\n";
    name = CLONE_PREFIX + copy.name;
    type = copy.type;
    sound = copy.sound;

}
Animal::~Animal() {
    cout << format("Destructor: {} the {}\n", name, type);
}

Animal& Animal::operator= (const Animal& copy) {
    cout << "Assignment operator\n";
    if (this != &copy) {
        name = copy.name;
        type = copy.type;
        sound = copy.sound;
    }

    return *this;
}

void Animal::print() const {
    cout << format("{} the {} says {}\n", name, type, sound);
}

unsigned long factorialWithoutRecursion(unsigned long n) {

    unsigned long factorial = n;
    while (n > 1) {
        factorial *= --n;
    }

    return factorial;
}

unsigned long factorial(unsigned long n) {
    if (n < 2) return 1;
    return n * factorial(n - 1);
}

void funcWithDefault(int a = 5) {
    cout << format("a is {}\n", a);
}

bool isPrime(short num) {

    if (num < 2) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    short diviser = 5;
    while (diviser * diviser <= num) {
        if (num % diviser == 0 || num % (diviser + 2) == 0) {
            return false;
        }
        diviser = diviser + 6;
    }

    return true;
}

void findPrimeNumbers() {
    // Natural number
    // Greater than 1
    // Not a product of two smaller natural numbers.

    const short limit = 31000;

    for ( int i = 2; i < limit; i++) {

        if (isPrime(i)) {
            cout << format("Number is a prime! {}\n", i);
        }
    }

}

void incrementAndDecrementOperators() {

    auto x = 5;
    cout << format("Foo BAAR! {}\n", ++x);
    cout << format("Foo BAAR! {}\n", --x);
    cout << format("Foo BAAR! {}\n", ++x);
    cout << format("Foo BAAR! {}\n", x--);
    cout << format("Foo BAAR! {}\n", x++);
    cout << format("Foo BAAR! {}\n", x++);
}

void compoundAssignmentOperators() {

    auto x = 5;
    auto y = 47;
    cout << format("x is {}\n", x);
    cout << format("y is {}\n", y);

    x *= y;
    cout << format("x is {}\n", x);
}

void commonOperators() {

    auto assignment = 5;

    auto addition = assignment + 2;
    auto subtraction = assignment - 2;
    auto modulo = assignment % 2;

    if (assignment != modulo) {
        cout << format("Not equal\n");
    }


    cout << format("Size of addition {} bits\n", sizeof(addition) * 8);
}

void structureType() {

    // Aggregate of variables

    struct S {
        int i {};
        double d {};
        const char * s {};
    };

    S s1 { 3, 4.54, "string one"};
    cout << format("s1: {}, {}, {}\n", s1.i, s1.d, s1.s);
}

void primitiveString() {

    const char s[] {"String"};
    cout << format("{}\n", s);

    // Essentially the same as the above in the background.
    const char null_terminated_s[] {'S', 't', 'r', 'i', 'n', 'g', 0};
    cout << format("{}\n", null_terminated_s);

    for (const char* p = s; *p; p++) {

        cout << format("{}\n", *p);
    }
}

// Also known as primitive array.
void cArray() {

    // Fixed sized container.
    // Zero indexed.
    int ia[5] {1, 2, 3, 4, 5};

    ia[0] = 1;

    // May also be assigned via pointer.
    // May also be access as if a pointer.
    // When incrementing a pointer, it increments the pointers
    // index, not the actual value.
    *ia = 2;

    int *pointer = ia;
    pointer++;

    for (const int& i : ia) {
        cout << format("{}", i);
    }
    cout << endl;
 }

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
    cArray();
    primitiveString();
    structureType();
    commonOperators();
    compoundAssignmentOperators();
    incrementAndDecrementOperators();
    findPrimeNumbers();
    funcWithDefault();
    cout << format("Initial factorial 5: {}\n", factorial(5));
    cout << format("W/ recursion factorial 5: {}\n", factorialWithoutRecursion(5));
    Animal unknown {};
    unknown.print();

    const Animal monkey {"primate", "steve", "ooo"};
    monkey.print();

    const Animal cloned_monkey = monkey;
    cloned_monkey.print();

    unknown = cloned_monkey;
    unknown.print();
}

