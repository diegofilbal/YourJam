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
    Node* tocando;

public:
    // Métodos da playlist
    Playlist();
    ~Playlist();

    bool adicionaMusicaInicio(Musica musica);
    bool adicionaMusicaFim(Musica musica);
    bool adicionaMusicaPos(int posicao, Musica musica);
    bool removeMusicaPos(int posicao);
    bool moveMusica(int pos_inicial, int pos_final, Musica musica);
    Musica* proxMusica();
    void mostraMusica();
    Lista* getLista();
    void setLista(Lista* lista);
    std::string getNome();
    void setNome(std::string);

};