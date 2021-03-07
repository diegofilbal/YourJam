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
    Lista(Lista &lista);
    ~Lista();

    bool insereInicio(Musica musica);
    bool insereFim(Musica musica);
    bool insereFim(Lista &lista);
    bool inserePos(int posicao, Musica musica);
    bool remove(int posicao);
    bool remove(Lista &lista);
    Node* busca(Musica musica);
    Node* buscaPos(int posicao);
    Musica* buscaMusica(Musica musica);
    Musica* buscaMusicaPos(int posicao);
    Lista* operator+(Lista &lista);
    void operator<<(Node *&node);
    void operator>>(Node *&node);
    void imprime();
    int getTamanho();
};