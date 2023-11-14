#include "doubleLinkedList.h"
#include <iostream>
#include <string>

int main() {
    std::string a;
    std::string b;
    std::string c;

    a = "1 test";
    b = "2 test";
    c = "3 test";

    DoubleLinkedList<std::string> ls;
    ls.addNode(a);
    ls.addNode(b);
    ls.addNode(c);

    return 0;


    return 0;
}
