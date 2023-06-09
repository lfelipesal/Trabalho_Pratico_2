#include "../include/Pilha.hpp"

Pilha::Pilha() : topoNo(nullptr), tamanho(0) {}

Pilha::~Pilha()
{
    while (!estaVazia())
    {
        desempilhar();
    }
}

void Pilha::empilhar(const T &valor)
{
    No *novoNo = new No(valor);
    novoNo->proximo = topoNo;
    topoNo = novoNo;
    tamanho++;
}

void Pilha::desempilhar()
{
    if (estaVazia())
    {
        std::cout << "A pilha está vazia. Não é possível desempilhar()." << std::endl;
        return;
    }
    No *temp = topoNo;
    topoNo = topoNo->proximo;
    delete temp;
    tamanho--;
}

T Pilha::topo() const
{
    if (estaVazia())
    {
        std::cout << "A pilha está vazia. Não há elemento no topo." << std::endl;
        return T();
    }
    return topoNo->dado;
}

bool Pilha::estaVazia() const
{
    return topoNo == nullptr;
}

int Pilha::getTamanho() const
{
    return tamanho;
}
