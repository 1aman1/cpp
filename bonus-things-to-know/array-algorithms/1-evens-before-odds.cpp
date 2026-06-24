#include<iostream>
using namespace std;

// Two-pointer technique to partition array: even numbers before odd numbers
// Time Complexity: O(n), Space Complexity: O(1)
void partition_evens_odds(int arr[], int n) {
  int left = 0, right = n - 1;
  while (left < right) {
    // Skip even numbers from left
    while (!(arr[left] & 1) && left < right)
      left++;
    // Skip odd numbers from right
    while (arr[right] & 1 && left < right)
      --right;
    // Swap if left is odd and right is even
    if (left < right) {
      int tmp = arr[left];
      arr[left] = arr[right];
      arr[right] = tmp;
    }
  }
}

// Alternative: Count and fill approach
// Time Complexity: O(n), Space Complexity: O(n)
void partition_evens_odds_counting(int arr[], int n) {
  int count_even = 0;
  for (int i = 0; i < n; ++i)
    if (arr[i] % 2 == 0)
      ++count_even;

  // First half for evens, second half for odds
  int temp[n];
  int even_idx = 0, odd_idx = count_even;
  for (int i = 0; i < n; ++i) {
    if (arr[i] % 2 == 0)
      temp[even_idx++] = arr[i];
    else
      temp[odd_idx++] = arr[i];
  }

  // Copy back to original array
  for (int i = 0; i < n; ++i)
    arr[i] = temp[i];
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original array: ";
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;

  // Using two-pointer approach
  partition_evens_odds(arr, n);
  cout << "After partition (two-pointer): ";
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;

  // Reset and try counting approach
  int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  partition_evens_odds_counting(arr2, n);
  cout << "After partition (counting): ";
  for (int i = 0; i < n; ++i)
    cout << arr2[i] << " ";
  cout << endl;

  return 0;
}
