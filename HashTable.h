#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2526_P1/ListLinked.h" 

template <typename V>
class HashTable : public Dict<V> {

    private:
        int n;   
        int max; 
        
        // Array de punteros a Listas Enlazadas.
        // Cada posición del array es una lista que contiene TableEntry<V>
        ListLinked<TableEntry<V>>* table;

         // Función Hash: Suma ASCII % tamaño
        int h(std::string key) {
            int sum = 0;
            for (char c : key) {
                sum += static_cast<int>(c);
            }
            return sum % max;
        }

    public:

        // Constructor
        HashTable(int size) {
            n = 0;
            max = size;
            table = new ListLinked<TableEntry<V>>[size];
        }

         // Destructor
        ~HashTable() {
            delete[] table;
        }

        // Devuelve el número de cubetas
        int capacity() {
            return max;
        }

         // Sobrecarga de << para imprimir la tabla
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << std::endl;
            out << "==============" << std::endl << std::endl;

            for (int i = 0; i < th.max; i++) {
                out << "== Cubeta " << i << " ==" << std::endl << std::endl;
                // Imprimimos la lista de esa cubeta
                // Asumimos que ListLinked tiene sobrecargado el operador <<
                out << th.table[i] << std::endl; 
            }

            out << "==============" << std::endl;
            return out;
        }

        // MÉTODOS HEREDADOS

         // Inserta un par clave-valor.
         //Si la clave existe, lanza error. Si no, añade al principio de la lista.

        void insert(std::string key, V value) override {
            int cubeta = h(key);

            // Usamos search de la lista.
            TableEntry<V> entry(key, value); // Entrada a insertar

            if (table[cubeta].search(entry) != -1) {
                throw std::runtime_error("Key '" + key + "' already exists!");
            }

            // Si no existe, insertamos al principio
            table[cubeta].prepend(entry);
            n++;
        }


         // Busca una clave y devuelve su valor.

        V search(std::string key) override {
            int cubeta = h(key);
            TableEntry<V> entryToFind(key); // Entrada dummy solo con clave

            int index = table[cubeta].search(entryToFind);

            if (index == -1) {
                throw std::runtime_error("Key '" + key + "' not found!");
            }

            return table[cubeta].get(index).value;
        }


        // Elimina una clave y devuelve su valor.

        V remove(std::string key) override {
            int cubeta = h(key);
            TableEntry<V> entryToFind(key);

            int index = table[cubeta].search(entryToFind);

            if (index == -1) {
                throw std::runtime_error("Key '" + key + "' not found!");
            }

            V val = table[cubeta].get(index).value;

            table[cubeta].remove(index);
            n--;

            return val;
      }
        // Devuelve el número de entradas
        int entries() override {
            return n;
        }

        // Operador para acceso directo
        V operator[](std::string key) {
            return search(key);
        }
};

#endif
