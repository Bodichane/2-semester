#include <iostream>
#include <cassert>

int main() {
    DoubleLinkedList<int> lst = {1, 2, 3, 4};
    assert(lst.to_string() == "[1, 2, 3, 4]");

    lst.push_front(0);
    lst.push_back(5);
    assert(lst.to_string() == "[0, 1, 2, 3, 4, 5]");

    lst.remove(2);
    assert(lst.to_string() == "[0, 1, 3, 4, 5]");

    lst[1] = 10;
    assert(lst.to_string() == "[0, 10, 3, 4, 5]");

    DoubleLinkedList<int> lst2 = lst;
    assert(lst2.to_string() == "[0, 10, 3, 4, 5]");

    lst2.clear();
    assert(lst2.to_string() == "[]");

    assert(!lst.empty());
    lst.clear();
    assert(lst.empty());

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
