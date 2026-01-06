#include <iostream>
#include "BSTree.h"

int main() {
    std::cout << "Creating BSTree<int> bstree ..." << std::endl << std::endl;
    BSTree<int> bstree;

    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << bstree << std::endl << std::endl;

    // Array de elementos para insertar
    int values[] = {15, 7, 3, 11, 9, 18, 21, 20};
    
    for(int val : values) {
        std::cout << "bstree.insert(" << val << ")" << std::endl;
        std::cout << "-----------------" << std::endl;
        bstree.insert(val);
        std::cout << "bstree.size(): " << bstree.size() << std::endl;
        std::cout << "bstree.search(" << val << "): " << bstree.search(val) << std::endl;
        std::cout << "cout << bstree: " << std::endl;
        std::cout << bstree << std::endl << std::endl;
    }

    // Tests de errores y excepciones
    try {
        std::cout << "bstree.search(0) => ";
        bstree.search(0);
    } catch(std::runtime_error &e) {
        std::cout << "OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }

    try {
        std::cout << "bstree.search(9) => ";
        bstree.search(9);
        std::cout << "OK! It did not throw std::runtime_error." << std::endl;
    } catch(std::runtime_error &e) {
        std::cout << "Fail!" << std::endl;
    }

    try {
        std::cout << "bstree.insert(9) => ";
        bstree.insert(9);
    } catch(std::runtime_error &e) {
        std::cout << "OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }

    try {
        std::cout << "bstree.remove(50) => ";
        bstree.remove(50);
    } catch(std::runtime_error &e) {
        std::cout << "OK! It throwed std::runtime_error: " << e.what() << std::endl << std::endl;
    }

    // Tests de borrado
    int remove_vals[] = {9, 11, 7, 15};
    for(int val : remove_vals) {
        std::cout << "bstree.remove(" << val << ")" << std::endl;
        std::cout << "----------------" << std::endl;
        bstree.remove(val);
        std::cout << "bstree.size(): " << bstree.size() << std::endl;
        std::cout << "cout << bstree: " << std::endl;
        std::cout << bstree << std::endl << std::endl;

        std::cout << "bstree.insert(" << val << ")" << std::endl;
        std::cout << "----------------" << std::endl;
        bstree.insert(val);
        std::cout << "bstree.size(): " << bstree.size() << std::endl;
        std::cout << "cout << bstree: " << std::endl;
        std::cout << bstree << std::endl << std::endl;
    }

    return 0;
}
