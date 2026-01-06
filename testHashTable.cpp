#include <iostream>
#include "HashTable.h"

int main() {
    try {
        HashTable<int> dict(3);

        std::cout << dict << std::endl;

        std::cout << "dict.capacity(): " << dict.capacity() << std::endl;
        std::cout << "dict.entries(): " << dict.entries() << std::endl;
        std::cout << std::endl;

        std::cout << "dict.insert('One', 1) ..." << std::endl;
        dict.insert("One", 1);
        std::cout << "dict.insert('Two', 2) ..." << std::endl;
        dict.insert("Two", 2);
        std::cout << "dict.insert('Three', 3) ..." << std::endl;
        dict.insert("Three", 3);
        std::cout << "dict.insert('Four', 4) ..." << std::endl;
        dict.insert("Four", 4);
        std::cout << "dict.insert('Five', 5) ..." << std::endl;
        dict.insert("Five", 5);
        std::cout << "dict.insert('Six', 6) ..." << std::endl;
        dict.insert("Six", 6);
        std::cout << std::endl << std::endl;

        //Imprimir estado
        std::cout << dict << std::endl;

        // Pruebas de búsqueda y acceso
        std::cout << "dict.search('One'): " << dict.search("One") << std::endl;
        std::cout << "dict['Four']: " << dict["Four"] << std::endl;
        
        // Prueba de borrado
        std::cout << "dict.remove('Three'): " << dict.remove("Three") << std::endl;
        std::cout << std::endl << std::endl;

        // Estado tras borrado
        std::cout << dict << std::endl;

        // Pruebas de errores
        try {
            std::cout << "dict.insert('One') => ";
            dict.insert("One", 11);
        } catch (std::exception &e) {
            std::cout << "throwed std::runtime_error: " << e.what() << std::endl;
        }

        try {
            std::cout << "dict.search('Ten') => ";
            dict.search("Ten");
        } catch (std::exception &e) {
            std::cout << "throwed std::runtime_error: " << e.what() << std::endl;
        }

        try {
            std::cout << "dict.remove('Ten') => ";
            dict.remove("Ten");
        } catch (std::exception &e) {
            std::cout << "throwed std::runtime_error: " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cout << "Excepción inesperada: " << e.what() << std::endl;
    }

    return 0;
}
