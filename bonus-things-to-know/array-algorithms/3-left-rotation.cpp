// Array Rotation: Shift elements left by d positions
// Using modulo arithmetic for elegant circular indexing

#include <iostream>
using namespace std;

// Approach 1: Using modulo to create virtual rotation (most elegant)
// Time: O(n), Space: O(1) - no extra array needed
void rotateUsingModulo(int arr[], int n, int shift) {
  cout << "After rotating left by " << shift << " positions: ";
  for (int i = 0; i < n; ++i)
    cout << arr[(i + shift) % n] << " ";
  cout << endl;
}

// Approach 2: Create rotated copy (common approach)
// Time: O(n), Space: O(n)
void rotateAndCopy(int arr[], int n, int shift) {
  int rotated[n];
  for (int i = 0; i < n; ++i)
    rotated[i] = arr[(i + shift) % n];

  cout << "After rotating left by " << shift << " positions: ";
  for (int i = 0; i < n; ++i)
    cout << rotated[i] << " ";
  cout << endl;
}

// Approach 3: In-place rotation using reversal (space-efficient)
// Time: O(n), Space: O(1)
void reverseArray(int arr[], int start, int end) {
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

void rotateUsingReversal(int arr[], int n, int shift) {
  shift = shift % n; // Handle shift >= n
  reverseArray(arr, 0, shift - 1);
  reverseArray(arr, shift, n - 1);
  reverseArray(arr, 0, n - 1);

  cout << "After rotating left by " << shift << " positions: ";
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5};
  int n = 5;
  int shift = 2;

  cout << "Original array: ";
  for (int i = 0; i < n; ++i)
    cout << arr1[i] << " ";
  cout << endl;

  // Method 1: Modulo approach (just prints, doesn't modify)
  rotateUsingModulo(arr1, n, shift);

  // Method 2: Copy approach
  rotateAndCopy(arr1, n, shift);

  // Method 3: In-place reversal
  int arr2[] = {1, 2, 3, 4, 5};
  rotateUsingReversal(arr2, n, shift);

  // Edge case: shift greater than array size
  cout << "\nEdge case - shift > n:" << endl;
  int arr3[] = {1, 2, 3, 4, 5};
  rotateUsingModulo(arr3, n, 7); // 7 % 5 = 2

  return 0;
}
