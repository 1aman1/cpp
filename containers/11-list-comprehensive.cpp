// std::list - Doubly Linked List Container
// Comprehensive demonstration of all major list operations

#include <iostream>
#include <list>
#include <numeric>
using namespace std;

void printList(const list<int>& lst, const string& label) {
  if (!lst.empty()) {
    cout << label << ": ";
    for (auto val : lst)
      cout << val << " ";
    cout << endl;
  } else {
    cerr << label << ": empty list" << endl;
  }
}

int main() {
  cout << "=== std::list Operations ===" << endl;

  list<int> list1;

  // Push operations: O(1) time
  cout << "\n1. Push operations:" << endl;
  for (int i = 0; i < 3; ++i)
    list1.push_front(i);  // Insert at front
  for (int i = 10; i < 13; ++i)
    list1.push_back(i);   // Insert at back
  printList(list1, "After push_front(0,1,2) + push_back(10,11,12)");

  // Access front and back: O(1) time
  cout << "\n2. Front/Back access:" << endl;
  cout << "Front: " << list1.front() << endl;
  cout << "Back: " << list1.back() << endl;

  // Reverse: modifies list in-place, O(n) time
  cout << "\n3. Reverse:" << endl;
  list1.reverse();
  printList(list1, "After reverse()");

  // Sort: modifies list in-place, O(n log n) time
  cout << "\n4. Sort:" << endl;
  list1.sort();
  printList(list1, "After sort()");

  // Emplace operations: construct in-place
  cout << "\n5. Emplace operations:" << endl;
  auto it = list1.begin();
  list1.emplace(it, 5);  // Insert 5 at first position
  printList(list1, "After emplace(begin(), 5)");

  list1.emplace_front(1);  // Insert at front
  list1.emplace_back(20);  // Insert at back
  printList(list1, "After emplace_front(1) + emplace_back(20)");

  // Assign: replace contents with n copies of value
  cout << "\n6. Assign:" << endl;
  list<int> list2;
  list2.assign(5, 100);
  printList(list2, "list2.assign(5, 100)");

  // Clone one list to another
  cout << "\n7. Clone list:" << endl;
  list<int> list3;
  list3.assign(list1.begin(), list1.end());
  printList(list3, "list3 (cloned from list1)");

  // Merge: combines two sorted lists
  cout << "\n8. Merge sorted lists:" << endl;
  list<int> list4;
  list4.push_back(15);
  list4.push_back(25);
  list3.merge(list4);
  printList(list3, "list3 after merge(list4)");
  printList(list4, "list4 after merge (should be empty)");

  // Remove: remove elements with specific value
  cout << "\n9. Remove operations:" << endl;
  list<int> list5;
  list5.assign({100, 100, 200, 100, 300}, list5.begin());
  printList(list5, "list5 initial");

  list5.remove(100);  // Remove all 100s
  printList(list5, "After remove(100)");

  // Remove_if: remove based on condition
  list<int> list6;
  list6.assign({1, 2, 3, 4, 5, 6}, list6.begin());
  list6.remove_if([](int x) { return x % 2 == 0; });  // Remove even numbers
  printList(list6, "After remove_if(even numbers)");

  // Unique: remove consecutive duplicates
  cout << "\n10. Unique operations:" << endl;
  list<int> list7;
  list7.assign({1, 1, 2, 2, 2, 3, 3, 1}, list7.begin());
  printList(list7, "list7 initial");

  list7.unique();
  printList(list7, "After unique() - removes consecutive duplicates");

  // Size and Clear
  cout << "\n11. Size and Clear:" << endl;
  cout << "list1.size() = " << list1.size() << endl;
  list1.clear();
  cout << "After clear(), size = " << list1.size() << endl;

  // Splice: move elements from one list to another
  cout << "\n12. Splice:" << endl;
  list<int> A;
  A.assign({1, 2, 3}, A.begin());
  list<int> B;
  B.assign({10, 20, 30}, B.begin());

  auto pos = A.begin();
  ++pos;  // Point to second element
  A.splice(pos, B);  // Insert all of B into A at position pos

  printList(A, "A after splice()");
  printList(B, "B after splice() (becomes empty)");

  cout << "\n=== Performance Notes ===" << endl;
  cout << "std::list is a DOUBLY-LINKED LIST" << endl;
  cout << "- O(1) insertion/deletion anywhere (if you have an iterator)" << endl;
  cout << "- O(n) random access (no indexing)" << endl;
  cout << "- Use when: frequent insertions/deletions in middle" << endl;
  cout << "- Avoid for: random access, memory efficiency" << endl;
  cout << "- Consider std::forward_list for single-linked list (less memory)" << endl;

  return 0;
}
