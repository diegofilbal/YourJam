#include <iostream>
#include <cstring>
#include "musica.hpp"
#include "node.hpp"
#include "lista.hpp"
#include "playlist.hpp"

// Construtor
Playlist::Playlist(){
    playlist = new Lista;
    playlist->setTamanho(0);
    tocando = nullptr;
}

// Destrutor
Playlist::~Playlist(){
    delete playlist;
}

// Adiciona uma música no início da playlist
bool Playlist::adicionaMusicaInicio(Musica musica){
    // A FAZER
    return true;
}

// Adiciona uma música no fim da playlist
bool Playlist::adicionaMusicaFim(Musica musica){
    // A FAZER
    return true;
}

// Adiciona uma música em uma posição específica da playlist
bool Playlist::adicionaMusicaPos(int pos, Musica musica){
    // A FAZER
    return true;
}

// Remove uma música em uma posição específica da playlist
bool Playlist::removeMusicaPos(int posicao){
    // A FAZER
    return true;
}

// Move uma música dentro da playlist
bool Playlist::moveMusica(int pos_inicial, int pos_final, Musica musica){
    // A FAZER
    return true;
}

Lista* Playlist::getLista(){
    return playlist;
}

void Playlist::setLista(Lista* lista){
    this->playlist = lista;
}

void Playlist::setNome(std::string nome){
    this->nome = nome;
}

std::string Playlist::getNome(){
    return nome;
}
