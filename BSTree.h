#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class BSTree {
    private:
        int nelem;
        BSNode<T> *root;

        // MÉTODOS PRIVADOS RECURSIVOS

        // Busca un elemento recursivamente
        BSNode<T>* search(BSNode<T>* n, T e) const {
            if (n == nullptr) {
                throw std::runtime_error("Element not found!");
            }
            else if (n->elem < e) {
                return search(n->right, e);
            }
            else if (n->elem > e) {
                return search(n->left, e);
            }
            else {
                return n;
            }
        }

        // Inserta un elemento recursivamente
        BSNode<T>* insert(BSNode<T>* n, T e) {
            if (n == nullptr) {
                return new BSNode<T>(e);
            }
            else if (n->elem == e) {
                throw std::runtime_error("Duplicated element!");
            }
            else if (n->elem < e) {
                n->right = insert(n->right, e);
            }
            else {
                n->left = insert(n->left, e);
            }
            return n;
        }

        // Recorrido Inorden: Izquierda -> Procesar -> Derecha
        void print_inorder(std::ostream &out, BSNode<T>* n) const {
            if (n != nullptr) {
                print_inorder(out, n->left);
                out << n->elem << " "; 
                print_inorder(out, n->right);
            }
        }

        // Elimina un elemento recursivamente
        BSNode<T>* remove(BSNode<T>* n, T e) {
            if (n == nullptr) {
                throw std::runtime_error("Element not found!");
            }
            else if (n->elem < e) {
                n->right = remove(n->right, e);
            }
            else if (n->elem > e) {
                n->left = remove(n->left, e);
            }
            else {
                // Elemento encontrado. Procedemos a borrar.
                
                // Caso: 2 descendientes
                if (n->left != nullptr && n->right != nullptr) {
                    n->elem = max(n->left);
                    n->left = remove_max(n->left);
                }
                // Cas  : 1 o 0 descendientes 
                else {
                    BSNode<T>* temp = n; // Guardamos puntero para borrar memoria
                    n = (n->left != nullptr) ? n->left : n->right;
                    delete temp;
                }
            }
            return n;
        }

        // Devuelve el valor máximo del subárbol 
        T max(BSNode<T>* n) const {
            if (n == nullptr) {
                throw std::runtime_error("Element not found!");
            }
            else if (n->right != nullptr) {
                return max(n->right);
            }
            else {
                return n->elem;
            }
        }

        // Elimina el nodo con el valor máximo del subárbol
        BSNode<T>* remove_max(BSNode<T>* n) {
            if (n->right == nullptr) {
                BSNode<T>* temp = n->left;
                delete n;
                return temp;
            }
            else {
                n->right = remove_max(n->right);
                return n;
            }
        }

        // Borrado reverso para el destructor
        void delete_cascade(BSNode<T>* n) {
            if (n != nullptr) {
                delete_cascade(n->left);
                delete_cascade(n->right);
                delete n;
            }
        }

    public:
        // MÉTODOS PÚBLICOS

        // Constructor
        BSTree() : nelem(0), root(nullptr) {}

        // Tamaño
        int size() const {
            return nelem;
        }

        // Búsqueda
        T search(T e) const {
            return search(root, e)->elem;
        }

        // Operador []
        T operator[](T e) const {
            return search(e);
        }

        // Inserción
        void insert(T e) {
            root = insert(root, e);
            nelem++;
        }

        // Operador de impresión
        friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst) {
            bst.print_inorder(out, bst.root);
            return out;
        }

        // Eliminación
        void remove(T e) {
            root = remove(root, e);
            nelem--;
        }

        // Destructor
        ~BSTree() {
            delete_cascade(root);
        }
};

#endif
