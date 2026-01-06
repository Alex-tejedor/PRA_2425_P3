#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree;

    public:
        // Constructor
        BSTreeDict() {
            tree = new BSTree<TableEntry<V>>();
        }

        // Destructor
        ~BSTreeDict() {
            delete tree;
        }

        // Implementación de la interfaz Dict
        
        // Insertar
        void insert(std::string key, V value) override {
            TableEntry<V> entry(key, value);
            tree->insert(entry);
        }

        // Buscar: Creamos una entrada solo con la clave y buscamos
        V search(std::string key) override {
            TableEntry<V> entryToFind(key);
            return tree->search(entryToFind).value;
        }

        // Borrar: Buscamos primero para guardar el valor, luego borramos
        V remove(std::string key) override {
            TableEntry<V> entryToRemove(key);
            
            // 1. Recuperamos el valor 
            V val = tree->search(entryToRemove).value;
            
            // 2. Borramos del árbol
            tree->remove(entryToRemove);
            
            // 3. Devolvemos el valor recuperado
            return val;
        }

        // Entradas
        int entries() override {
            return tree->size();
        }

        // Sobrecarga operador []
        V operator[](std::string key) {
            return search(key);
        }

        // Sobrecarga salida estándar
        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs) {
            out << *(bs.tree); // Delegamos en el operator<< del BSTree
            return out;
        }
};

#endif
