#include <iostream>
#include "singly_linked_list.hpp"

int main() {
    auto list = ais1002::singly_linked_list<std::string>();

    list.add("hello");
    list.add("per");
    list.add("nils");

    list.print();

    std:: cout << list.removeFirst() << std::endl;

    list.print();

    list.insert(0, "olav");

    list.insert(list.size(), "olav2");

    list.print();

    return 0;
}
