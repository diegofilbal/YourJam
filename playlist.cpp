#include <iostream>
#include <cstring>
#include "musica.hpp"
#include "node.hpp"
#include "lista.hpp"
#include "playlist.hpp"

// Construtor
Playlist::Playlist(){
    playlist = new Lista;
    tocando = nullptr;
}

// Destrutor
Playlist::~Playlist(){
    delete playlist;
}

// Adiciona uma música no início da playlist
bool Playlist::adicionaMusicaInicio(Musica musica){
    return playlist->insereInicio(musica); // Retorna código retornado pela função da classe Lista
}

// Adiciona uma música no fim da playlist
bool Playlist::adicionaMusicaFim(Musica musica){
    return playlist->insereFim(musica); // Retorna código retornado pela função da classe Lista
}

// Adiciona uma música em uma posição específica da playlist
bool Playlist::adicionaMusicaPos(int pos, Musica musica){
    return playlist->inserePos(pos, musica); // Retorna código retornado pela função da classe Lista
}

// Remove uma música em uma posição específica da playlist
void Playlist::removeMusicaPos(int posicao){
    playlist->removePos(posicao); // Retorna código retornado pela função da classe Lista
}

// Move uma música dentro da playlist
bool Playlist::moveMusica(int pos_inicial, int pos_final, Musica musica){
    // A FAZER
    return true;
}

// Imprime as músicas da playlist recursivamente
void Playlist::imprime(Node* node, int contador){
    if(node == nullptr){
        return;
    }
    std::cout << contador << ". " << node->musica->getArtista() << " - " << node->musica->getNome() << std::endl;
    imprime(node->next, contador + 1);
}

// Retorna a playlist
Lista* Playlist::getLista(){
    return playlist;
}

// Descarta a lista antiga e faz uma cópia da lista recebida
void Playlist::setLista(Lista* lista){

    int tamanho_pl = this->playlist->getTamanho();

    for (int i = 0; i < tamanho_pl; i++){ // Remove todos os elementos antigos
        this->playlist->removePos(0);
    }

    if(lista != nullptr){ // Verifica se o ponteiro não é nulo
        tamanho_pl = lista->getTamanho();

        for (int i = 0; i < tamanho_pl; i++){ // Insere todos os elementos da nova lista na lista original
            this->playlist->insereFim(*lista->buscaMusicaPos(i));
        }
    }    
}

// Define o nome da playlist
void Playlist::setNome(std::string nome){
    this->nome = nome;
}

// Retorna o nome da playlist
std::string Playlist::getNome(){
    return nome;
}
