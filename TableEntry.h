#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
    public:
        std::string key;
        V value;

        // Constructores

        // Constructor con clave y valor
        TableEntry(std::string key, V value) : key(key), value(value) {}

        // Constructor solo con clave
        TableEntry(std::string key) : key(key), value() {}

        // Constructor por defecto
        TableEntry() : key(""), value() {}

        // Sobrecarga de Operadores

        // Dos entradas son iguales si tienen la misma clave
        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2) {
            return te1.key == te2.key;
        }

        // Dos entradas son distintas si tienen distinta clave
        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
            return te1.key != te2.key;
        }

        // Operador para imprimir
        friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te) {
            out << "('" << te.key << "' => " << te.value << ")";
            return out;
        }
};

#endif
