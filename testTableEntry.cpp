#include <iostream>
#include <string>
#include "TableEntry.h"

int main() {
    TableEntry<int> e1("Catorze", 14);
    TableEntry<int> e2("Trenta-tres", 33);
    TableEntry<int> e3("Trenta-tres", 123);

    std::cout << "e1: " << e1 << std::endl;
    std::cout << "e2: " << e2 << std::endl;
    std::cout << "e3: " << e3 << std::endl;
    std::cout << std::endl;

    std::cout << "e1 == e2 ? " << std::boolalpha << (e1 == e2) << std::endl;
    std::cout << "e1 != e2 ? " << std::boolalpha << (e1 != e2) << std::endl;
    std::cout << std::endl;

    std::cout << "e1 == e3 ? " << std::boolalpha << (e1 == e3) << std::endl;
    std::cout << "e1 != e3 ? " << std::boolalpha << (e1 != e3) << std::endl;
    std::cout << std::endl;

    std::cout << "e2 == e3 ? " << std::boolalpha << (e2 == e3) << std::endl;
    std::cout << "e2 != e3 ? " << std::boolalpha << (e2 != e3) << std::endl;

    return 0;
}
