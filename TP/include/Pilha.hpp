#pragma once

template <typename T>
class Pilha
{
private:
    struct No
    {
        T dado;
        No *proximo;
        No(const T &valor) : dado(valor), proximo(nullptr) {}
    };

    No *topoNo;
    int tamanho;

public:
    Pilha();
    ~Pilha();

    void empilhar(const T &valor);
    void desempilhar();
    T topo() const;
    bool estaVazia() const;
    int getTamanho() const;
};