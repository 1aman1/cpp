// Basic Pointer Operations
// Demonstrates pointer fundamentals: declarations, dereferencing, and pointer-to-pointer

#include <iostream>
using namespace std;

int main() {
  // Basic variable and pointer
  int a = 9415;
  int* ptr = nullptr;      // Pointer to int
  int** _ptr = nullptr;    // Pointer to pointer (double indirection)

  // Initialize pointers
  ptr = &a;                // ptr points to address of 'a'
  _ptr = &ptr;             // _ptr points to address of 'ptr'

  // Display information
  cout << "=== Basic Pointer Information ===" << endl;
  cout << "variable a: " << a << endl;
  cout << "address of a: " << &a << endl << endl;

  cout << "=== Pointer (ptr) ===" << endl;
  cout << "ptr (stores address): " << ptr << endl;
  cout << "*ptr (dereference - value at address): " << *ptr << endl;
  cout << "&ptr (address of pointer itself): " << &ptr << endl << endl;

  cout << "=== Pointer to Pointer (_ptr) ===" << endl;
  cout << "_ptr (stores address of ptr): " << _ptr << endl;
  cout << "*_ptr (dereference - value at ptr): " << *_ptr << endl;
  cout << "**_ptr (double dereference - value of a): " << **_ptr << endl;
  cout << "&_ptr (address of _ptr itself): " << &_ptr << endl << endl;

  // Modifying through pointers
  cout << "=== Modification Through Pointers ===" << endl;
  *ptr = 100;  // Modify 'a' through ptr
  cout << "After *ptr = 100:" << endl;
  cout << "a = " << a << endl;
  cout << "**_ptr = " << **_ptr << endl;

  // Pointer arithmetic example
  cout << "\n=== Pointer Arithmetic ===" << endl;
  int arr[] = {10, 20, 30, 40, 50};
  int* p = arr;
  cout << "Array: ";
  for (int i = 0; i < 5; ++i)
    cout << p[i] << " ";
  cout << endl;

  cout << "Access via pointer arithmetic:" << endl;
  cout << "*p = " << *p << " (first element)" << endl;
  cout << "*(p+2) = " << *(p + 2) << " (third element)" << endl;
  cout << "p[3] = " << p[3] << " (fourth element)" << endl;

  return 0;
}
