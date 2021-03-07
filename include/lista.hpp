#pragma once

#include <string>
#include "musica.hpp"
#include "node.hpp"

class Lista{
private:
    // Atributos da lista
    Node *head, *tail;
    int tamanho;

public:
    // Métodos da lista
    Lista();
    Lista(Lista const &lista);
    ~Lista();

    bool insereInicio(Musica musica);
    bool insereFim(Musica musica);
    bool insereFim(Lista const &lista);
    bool inserePos(int posicao, Musica musica);

    bool remove(int posicao);
    bool remove(Lista const &lista);

    Node* busca(Musica musica) const;
    Node* buscaPos(int posicao) const;
    Musica* buscaMusica(Musica musica) const;
    Musica* buscaMusicaPos(int posicao) const;

    Lista* operator+(Lista const &lista) const;
    void operator>>(Node *&node);
    void operator<<(Node *&node);

    void imprime() const;
    
    int getTamanho() const;
};