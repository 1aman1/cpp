// STL Numeric & Algorithm Algorithms
// Comprehensive demonstration of <numeric> and <algorithm> operations

#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  cout << "=== NUMERIC ALGORITHMS ===" << endl;

  vector<int> vec(15);

  // iota: Fill with sequentially increasing values
  cout << "\n1. iota - Fill with sequential values:" << endl;
  iota(vec.begin(), vec.end(), 1);  // Fill with 1, 2, 3, ..., 15
  cout << "After iota(begin, end, 1): ";
  for (auto i : vec)
    cout << i << " ";
  cout << endl;

  // accumulate: Sum all elements
  cout << "\n2. accumulate - Sum elements:" << endl;
  int sum = accumulate(vec.cbegin(), vec.cend(), 0);  // Initial value: 0
  cout << "Sum: " << sum << endl;

  // accumulate with custom operation
  int product = accumulate(vec.cbegin(), vec.cend(), 1, [](int a, int b) {
    return a * b;  // Multiply instead of add
  });
  cout << "Product of first 3 elements: " << product << endl;

  cout << "\n=== SEARCHING ALGORITHMS ===" << endl;

  // max_element and min_element
  cout << "\n3. max_element / min_element:" << endl;
  cout << "Max element: " << *max_element(vec.cbegin(), vec.cend()) << endl;
  cout << "Min element: " << *min_element(vec.cbegin(), vec.cend()) << endl;

  // count: Count occurrences of a value
  cout << "\n4. count - Count occurrences:" << endl;
  cout << "Count of 5: " << count(vec.cbegin(), vec.cend(), 5) << endl;

  // find: Find first occurrence
  cout << "\n5. find - Find first occurrence:" << endl;
  auto it = find(vec.cbegin(), vec.cend(), 7);
  if (it != vec.end()) {
    cout << "Found value 7 at position: " << distance(vec.begin(), it) << endl;
  } else {
    cout << "Value 7 not found" << endl;
  }

  cout << "\n=== BOUND OPERATIONS (for sorted ranges) ===" << endl;

  // lower_bound and upper_bound
  vector<int> sorted_vec = {10, 10, 10, 20, 20, 30, 40};
  cout << "\nSorted vector: ";
  for (auto x : sorted_vec)
    cout << x << " ";
  cout << endl;

  cout << "\n6. lower_bound - First element >= value:" << endl;
  auto lower = lower_bound(sorted_vec.begin(), sorted_vec.end(), 20);
  cout << "lower_bound(20) at index: " << distance(sorted_vec.begin(), lower) << endl;

  cout << "\n7. upper_bound - First element > value:" << endl;
  auto upper = upper_bound(sorted_vec.begin(), sorted_vec.end(), 20);
  cout << "upper_bound(20) at index: " << distance(sorted_vec.begin(), upper) << endl;

  cout << "\n=== PERMUTATION ALGORITHMS ===" << endl;

  // next_permutation and prev_permutation
  vector<int> perm = {1, 2, 3};
  cout << "\n8. next_permutation:" << endl;
  cout << "Starting permutation: ";
  for (auto x : perm)
    cout << x << " ";
  cout << endl;

  while (next_permutation(perm.begin(), perm.end())) {
    cout << "Next permutation: ";
    for (auto x : perm)
      cout << x << " ";
    cout << endl;
  }

  // Reset for prev_permutation
  vector<int> perm2 = {3, 2, 1};
  cout << "\n9. prev_permutation:" << endl;
  cout << "Starting permutation: ";
  for (auto x : perm2)
    cout << x << " ";
  cout << endl;

  if (prev_permutation(perm2.begin(), perm2.end())) {
    cout << "Previous permutation: ";
    for (auto x : perm2)
      cout << x << " ";
    cout << endl;
  }

  cout << "\n=== UTILITY OPERATIONS ===" << endl;

  // distance: Get distance between iterators
  cout << "\n10. distance - Get iterator distance:" << endl;
  vector<int> test = {10, 20, 30, 40, 50};
  auto it_begin = test.begin();
  auto it_end = test.end();
  cout << "Distance from begin to end: " << distance(it_begin, it_end) << endl;

  auto it_target = find(test.begin(), test.end(), 30);
  cout << "Distance from begin to element 30: " << distance(test.begin(), it_target) << endl;

  // erase and size
  cout << "\n11. erase and size:" << endl;
  cout << "Initial size: " << test.size() << endl;
  test.erase(test.begin());  // Remove first element
  cout << "After erase(first): " << test.size() << endl;

  cout << "\n=== PRACTICAL EXAMPLE ===" << endl;
  vector<int> data = {1, 200, 3, 40, 5, 60, 7};
  cout << "\nData: ";
  for (auto x : data)
    cout << x << " ";
  cout << endl;

  cout << "Count values > 50: " << count_if(data.begin(), data.end(), [](int x) {
    return x > 50;
  }) << endl;

  cout << "Sum of all values: " << accumulate(data.begin(), data.end(), 0) << endl;
  cout << "Average: "
       << (double)accumulate(data.begin(), data.end(), 0) / data.size() << endl;

  return 0;
}
