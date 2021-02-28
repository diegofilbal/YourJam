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
    ~Lista();

    bool insereInicio(Musica musica);
    bool insereFim(Musica musica);
    bool insereFim(Lista &lista);
    bool inserePos(int posicao, Musica musica);
    void removePos(int posicao);
    Node* busca(Musica musica);
    Node* buscaPos(int posicao);
    Musica* buscaMusica(Musica musica);
    Musica* buscaMusicaPos(int posicao);
    void imprime();
    int getTamanho();
};