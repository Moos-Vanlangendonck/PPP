#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void variableTypes();
void simpleCalculator();
void numberChecker();
void gradeCalculator();
int factorial(int n);
void print(int value);
void print(double value);
void arrayAverage();
void stringReversal();
void pointerSwap(int* a, int* b);
void referenceFunction(int& value);
class Rectangle;
class Book;
void animalSpeakDemo();
void fileWritingDemo();
void fileReadingDemo();

int main() {
     1. Basic Syntax and Data Types
     variableTypes();
     simpleCalculator();

     2. Control Structures
     numberChecker();
     gradeCalculator();

     3. Functions
     cout << "Factorial of 5: " << factorial(5) << endl;
     print(5);
     print(5.5);

     4. Arrays and Strings
     arrayAverage();
     stringReversal();

     5. Pointers and References
     int a = 5, b = 10;
     pointerSwap(&a, &b);
     cout << "After swapping: a = " << a << ", b = " << b << endl;

     int num = 5;
     referenceFunction(num);
     cout << "After reference function: num = " << num << endl;

     6. Classes and Objects
     animalSpeakDemo();

     7. Inheritance
     animalSpeakDemo();

     8. File I/O
     fileWritingDemo();
     fileReadingDemo();

    return 0;
}

// Exercise 1.1: Variable Types
void variableTypes() {
    int intVar = 10;
    float floatVar = 5.5f;
    char charVar = 'A';
    bool boolVar = true;

    cout << "Integer: " << intVar << " Size: " << sizeof(intVar) << " bytes" << endl;
    cout << "Float: " << floatVar << " Size: " << sizeof(floatVar) << " bytes" << endl;
    cout << "Char: " << charVar << " Size: " << sizeof(charVar) << " bytes" << endl;
    cout << "Bool: " << boolVar << " Size: " << sizeof(boolVar) << " bytes" << endl;
}

// Exercise 1.2: Simple Calculator
void simpleCalculator() {
    double num1, num2;
    char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    switch (op) {
        case '+':
            cout << "Result: " << (num1 + num2) << endl;
            break;
        case '-':
            cout << "Result: " << (num1 - num2) << endl;
            break;
        case '*':
            cout << "Result: " << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << (num1 / num2) << endl;
            else 
                cout << "Division by zero error." << endl;
            break;
        default:
            cout << "Invalid operator." << endl;
            break;
    }
}

// Exercise 2.1: Number Checker
void numberChecker() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (number % 2 == 0)
        cout << number << " is even." << endl;
    else
        cout << number << " is odd." << endl;
}

// Exercise 2.2: Grade Calculator
void gradeCalculator() {
    int score;
    cout << "Enter student's score: ";
    cin >> score;

    if (score >= 90)
        cout << "Grade: A" << endl;
    else if (score >= 80)
        cout << "Grade: B" << endl;
    else if (score >= 70)
        cout << "Grade: C" << endl;
    else if (score >= 60)
        cout << "Grade: D" << endl;
    else
        cout << "Grade: F" << endl;
}

// Exercise 3.1: Function to Calculate Factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Exercise 3.2: Function Overloading
void print(int value) {
    cout << "Integer: " << value << endl;
}

void print(double value) {
    cout << "Double: " << value << endl;
}

// Exercise 4.1: Array Average
void arrayAverage() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;

    for (int i = 0; i < 10; i++)
        sum += arr[i];

    cout << "Average: " << static_cast<double>(sum) / 10 << endl;
}

// Exercise 4.2: String Reversal
void stringReversal() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string reversedStr = string(str.rbegin(), str.rend());
    cout << "Reversed string: " << reversedStr << endl;
}

// Exercise 5.1: Pointer Swap
void pointerSwap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Exercise 5.2: Reference Function
void referenceFunction(int& value) {
    value *= 2;
}

// Exercise 6.1: Basic Class Implementation
class Rectangle {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() {
        return width * height;
    }
};

// Exercise 6.2: Constructor and Destructor
class Book {
private:
    string title, author;

public:
    Book(string t, string a) : title(t), author(a) {
        cout << "Book '" << title << "' by " << author << " created." << endl;
    }

    ~Book() {
        cout << "Book '" << title << "' destroyed." << endl;
    }
};

// Exercise 7.1: Base and Derived Classes
class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow!" << endl;
    }
};

// Function to demo animal speaking
void animalSpeakDemo() {
    Dog dog;
    Cat cat;
    Animal* animalPtr;

    animalPtr = &dog;
    animalPtr->speak();

    animalPtr = &cat;
    animalPtr->speak();
}

// Exercise 8.1: Writing to a File
void fileWritingDemo() {
    ofstream outFile("squares.txt");
    for (int i = 1; i <= 10; i++) {
        outFile << i * i << endl;
    }
    outFile.close();
    cout << "Squares written to squares.txt." << endl;
}

// Exercise 8.2: Reading from a File
void fileReadingDemo() {
    ifstream inFile("squares.txt");
    int number, sum = 0;

    if (inFile.is_open()) {
        while (inFile >> number) {
            sum += number;
        }
        inFile.close();
    } else {
        cout << "Unable to open the file." << endl;
    }
    
    cout << "Sum of squares: " << sum << endl;
}
