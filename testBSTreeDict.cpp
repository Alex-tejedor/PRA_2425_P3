#include <iostream>
#include <string>
#include "BSTreeDict.h"

int main() {
    std::cout << "Creating BSTreeDict<int> dict ..." << std::endl << std::endl;
    BSTreeDict<int> dict;

    std::cout << "dict.entries(): " << dict.entries() << std::endl;
    std::cout << "cout << dict: " << dict << std::endl << std::endl;

    // Pruebas de inserción
    std::cout << "dict.insert('c', 3) ..." << std::endl;
    dict.insert("c", 3);
    std::cout << "dict.insert('f', 6) ..." << std::endl;
    dict.insert("f", 6);
    std::cout << "dict.insert('a', 1) ..." << std::endl;
    dict.insert("a", 1);
    std::cout << "dict.insert('b', 2) ..." << std::endl;
    dict.insert("b", 2);
    std::cout << "dict.insert('d', 4) ..." << std::endl;
    dict.insert("d", 4);
    std::cout << "dict.insert('e', 5) ..." << std::endl;
    dict.insert("e", 5);
    std::cout << std::endl;

    // Imprimir
    std::cout << "cout << dict: " << std::endl;
    std::cout << dict << std::endl << std::endl;

    // Pruebas de búsqueda y acceso
    std::cout << "dict.search('a'): " << dict.search("a") << std::endl;
    std::cout << "dict['d']: " << dict["d"] << std::endl;
    
    // Prueba de borrado
    std::cout << "dict.remove('c'): " << dict.remove("c") << std::endl;
    std::cout << std::endl;

    std::cout << dict << std::endl << std::endl;

    // Pruebas de manejo de errores
    try {
        std::cout << "dict.insert('a') => ";
        dict.insert("a", 10);
    } catch(std::runtime_error &e) {
        std::cout << "OK! throwed std::runtime_error: " << e.what() << std::endl;
    }

    try {
        std::cout << "dict.search('j') => ";
        dict.search("j");
    } catch(std::runtime_error &e) {
        std::cout << "OK! throwed std::runtime_error: " << e.what() << std::endl;
    }

    try {
        std::cout << "dict.remove('c') => ";
        dict.remove("c");
    } catch(std::runtime_error &e) {
        std::cout << "OK! throwed std::runtime_error: " << e.what() << std::endl;
    }

    return 0;
}
