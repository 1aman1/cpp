// Leaders in Array: Find elements greater than all elements to their right
// An element is a leader if it is greater than all elements to its right
// The last element is always a leader

#include <iostream>
using namespace std;

// Naive approach: O(n^2) time, O(1) space
void findLeadersNaive(int arr[], int n) {
  cout << "Leaders (naive): ";
  for (int i = 0; i < n; ++i) {
    int j;
    for (j = i + 1; j < n; ++j) {
      if (arr[i] <= arr[j])
        break;
    }
    // If j reached end, no larger element found to the right
    if (j == n)
      cout << arr[i] << " ";
  }
  cout << endl;
}

// Optimized approach: O(n) time, O(1) space
// Traverse from right to left, keeping track of max seen so far
void findLeadersOptimized(int arr[], int n) {
  cout << "Leaders (optimized): ";
  int max_so_far = arr[n - 1];
  cout << max_so_far << " ";

  // Traverse from second last to first
  for (int i = n - 2; i >= 0; --i) {
    if (arr[i] > max_so_far) {
      cout << arr[i] << " ";
      max_so_far = arr[i];
    }
  }
  cout << endl;
}

int main() {
  int arr[] = {16, 17, 4, 3, 5, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Array: ";
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;

  findLeadersNaive(arr, n);
  findLeadersOptimized(arr, n);

  // Another example
  int arr2[] = {5, 4, 3, 2, 1};
  cout << "\nArray: ";
  for (int i = 0; i < 5; ++i)
    cout << arr2[i] << " ";
  cout << endl;

  findLeadersNaive(arr2, 5);
  findLeadersOptimized(arr2, 5);

  return 0;
}
