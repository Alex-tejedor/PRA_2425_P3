#ifndef DICT_H
#define DICT_H

#include <string>

template <typename V>
class Dict {
    public:

        // Destructor virtual
        virtual ~Dict() {}

        // Métodos virtuales

        // Inserta el par key->value
        virtual void insert(std::string key, V value) = 0;

        // Busca y devuelve el valor asociado a key
        virtual V search(std::string key) = 0;

        // Elimina el par key->value y devuelve el valor
        virtual V remove(std::string key) = 0;

        // Devuelve el número de elementos en el diccionario.
        virtual int entries() = 0;
};

#endif
