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
    int proxima;

public:
    // Métodos da playlist
    Playlist();
    Playlist(Playlist const &playlist);
    ~Playlist();

    bool insereInicio(Musica musica);
    bool insereFim(Musica musica);
    bool insereFim(Playlist const &playlist);
    bool inserePos(int posicao, Musica musica);

    bool remove(int posicao);
    int remove(Playlist const &playlist);

    void moveMusica(int pos_inicial, int pos_final);

    Musica* proxMusica();

    Playlist* operator+(Playlist const &playlist) const;
    Playlist* operator+(Musica const &musica) const;
    Playlist* operator-(Playlist const &playlist) const;
    Playlist* operator-(Musica const &musica) const;
    void operator<<(Musica *&musica);

    void imprime(Node *const node, int contador) const;

    Lista *getLista() const;
    void setLista(Lista* const lista);

    std::string getNome() const;
    void setNome(std::string nome);

};