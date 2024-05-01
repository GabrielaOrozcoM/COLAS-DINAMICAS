#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

#include <iostream>

template<class T>
class ColaDinamica;

template<class T>
class node {
private:
    T data;
    node<T>* sig;
public:
    node() : sig(nullptr) {}
    node(const T& data) : data(data), sig(nullptr) {}
    T getData() const { return data; }
    node<T>* getSig() const { return sig; }
    friend class ColaDinamica<T>;
};

template<class T>
class ColaDinamica {
private:
    node<T>* frente;
    node<T>* fin;
public:
    ColaDinamica() : frente(nullptr), fin(nullptr) {}
    bool vacia() const;
    void encolar(const T& elem);
    bool desencolar();
    void imprimir() const;
    T frenteCola() const;
};

template<class T>
bool ColaDinamica<T>::vacia() const {
    return frente == nullptr;
}

template<class T>
void ColaDinamica<T>::encolar(const T& elem) {
    node<T>* nuevo = new node<T>(elem);
    if (vacia()) {
        frente = nuevo;
        fin = nuevo;
    } else {
        fin->sig = nuevo;
        fin = nuevo;
    }
}

template<class T>
bool ColaDinamica<T>::desencolar() {
    if (vacia()) {
        return false;
    }
    node<T>* temp = frente;
    frente = frente->sig;
    if (frente == nullptr) {
        fin = nullptr;
    }
    delete temp;
    return true;
}

template<class T>
void ColaDinamica<T>::imprimir() const {
    node<T>* temp = frente;
    while (temp!= nullptr) {
        std::cout << temp->data << " ";
        temp = temp->sig;
    }
    std::cout << "\n";
}

template<class T>
T ColaDinamica<T>::frenteCola() const {
    if (vacia()) {
        throw std::out_of_range("La cola está vacía.");
    }
    return frente->data;
}

#endif // COLADINAMICA_H_INCLUDED
