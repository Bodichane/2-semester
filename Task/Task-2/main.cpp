#include "doubleLinkedList.h"
#include <iostream>

int main() {
  DoubleLinkedList<int> lst = {1, 2, 3, 4};
  std::cout << "Initial list: " << lst << std::endl;

  lst.push_front(0);
  lst.push_back(5);
  std::cout << "List after push_front(0) and push_back(5): " << lst
            << std::endl;

  lst.remove(2);
  std::cout << "List after removing element at index 2: " << lst << std::endl;

  lst[1] = 10;
  std::cout << "List after setting element at index 1 to 10: " << lst
            << std::endl;

  DoubleLinkedList<int> lst2 = lst;
  std::cout << "Copy of the list: " << lst2 << std::endl;

  lst2.clear();
  std::cout << "Empty list: " << lst2 << std::endl;

  std::cout << "Is the list empty? " << (lst.empty() ? "yes" : "no")
            << std::endl;
  
  return 0;
}
