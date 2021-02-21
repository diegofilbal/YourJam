#pragma once

#include <string>
#include "musica.hpp"
#include "node.hpp"
#include "lista.hpp"

class Playlist{
private:
    // Atributos da playlist
    std::string nome;
    Lista* playlist;
    int tocando;

public:
    // Métodos da playlist
    Playlist();
    ~Playlist();

    bool adicionaMusicaInicio(Musica musica);
    bool adicionaMusicaFim(Musica musica);
    bool adicionaMusicaPos(int posicao, Musica musica);
    void removeMusicaPos(int posicao);
    void moveMusica(int pos_inicial, int pos_final);
    void imprime(Node* node, int contador);
    Musica *proxMusica();
    Lista* getLista();
    void setLista(Lista* lista);
    std::string getNome();
    void setNome(std::string);

};