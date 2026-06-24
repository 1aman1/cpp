// Returning Lvalue References from Functions
// Demonstrates advanced reference concepts: functions returning mutable references
// WARNING: This is powerful but dangerous - can create dangling references!

#include <iostream>
using namespace std;

// Function that returns a reference to a parameter
// This allows modification of the caller's variable through the returned reference
int& getReference(int& x) {
  return x;  // Safe: x is a parameter (caller's variable)
}

// This is DANGEROUS - DO NOT DO THIS!
// Returns reference to a local variable that will be destroyed
int& dangerousReturn() {
  int local = 42;
  return local;  // UNDEFINED BEHAVIOR! local is destroyed after return
}

// Safe example: returning reference to member variable
class Value {
private:
  int data;

public:
  Value(int val) : data(val) {}

  // Returns reference to member variable
  int& getData() {
    return data;
  }

  void print() {
    cout << "data = " << data << endl;
  }
};

int main() {
  // Example 1: Modifying through returned reference
  cout << "=== Example 1: Reference to Parameter ===" << endl;
  int original = 42;
  cout << "Original value: " << original << endl;

  // Get reference and modify through it
  getReference(original) = 99;
  cout << "After getReference(original) = 99: " << original << endl << endl;

  // Example 2: Using returned reference as lvalue
  cout << "=== Example 2: Returned Reference as Lvalue ===" << endl;
  int a = 5;
  int& ref = getReference(a);
  cout << "Initial a: " << a << endl;

  ref = 100;  // Modifies 'a' through the returned reference
  cout << "After ref = 100: " << a << endl << endl;

  // Example 3: Chaining modifications
  cout << "=== Example 3: Chaining Through References ===" << endl;
  int b = 10;
  getReference(b) = 25;
  getReference(b) += 5;  // Add 5 to b
  cout << "After getReference(b) += 5: " << b << endl << endl;

  // Example 4: Safe class member reference
  cout << "=== Example 4: Class Member Reference ===" << endl;
  Value obj(50);
  obj.print();

  int& memberRef = obj.getData();
  memberRef = 200;  // Modify member through returned reference

  obj.print();
  cout << endl;

  // Example 5: Why returning local references is dangerous
  cout << "=== Example 5: Dangling References (DO NOT DO THIS) ===" << endl;
  cout << "This demonstrates undefined behavior - don't uncomment!" << endl;
  // int& bad = dangerousReturn();
  // cout << bad;  // Undefined behavior! Reading memory that's been freed
  // The local variable 'local' was destroyed, so bad refers to invalid memory

  return 0;
}
