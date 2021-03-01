#include <iostream>
#include <cstring>
#include "musica.hpp"
#include "node.hpp"
#include "lista.hpp"
#include "playlist.hpp"

// Construtor
Playlist::Playlist(){
    playlist = new Lista;
    proxima = 0;
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
    playlist->remove(posicao); // Retorna código retornado pela função da classe Lista
}

// Move uma música dentro da playlist
void Playlist::moveMusica(int pos_inicial, int pos_final){

    Musica musica;// Variável a receber as informações da musica a ser movida

    // Copia as informações da música a ser movida
    musica.setNome(playlist->buscaMusicaPos(pos_inicial - 1)->getNome());
    musica.setArtista(playlist->buscaMusicaPos(pos_inicial - 1)->getArtista());

    playlist->remove(pos_inicial); // Remove a música da posição atual
    playlist->inserePos(pos_final, musica); // Insere a música na posição para qual o usuário deseja movê-la
}

// Imprime as músicas da playlist recursivamente
void Playlist::imprime(Node* node, int contador){
    if(node == nullptr){ // Verifica se a lista já chegou ao fim
        return;
    }
    std::cout << contador << ". " << node->musica->getNome() << " - " << node->musica->getArtista() << std::endl;
    imprime(node->next, contador + 1); // Faz a chamada recursiva para a immressão do próximo node 
}

// Retorna a próxima música a ser tocada
Musica* Playlist::proxMusica(){

    Node *node = playlist->buscaPos(proxima); // Recebe o node que armazena a próxima música a ser tocada

    if(node != nullptr){ // Verifica se ainda há música para tocar
        proxima++;
        return node->musica; // Retorna a música 
    }

    return nullptr; // A reprodução das músicas chegou ao fim
}

// Retorna a playlist
Lista* Playlist::getLista(){
    return playlist;
}

// Descarta a lista antiga e faz uma cópia da lista recebida
void Playlist::setLista(Lista* lista){

    int tamanho_pl = playlist->getTamanho(); // Recebe o tamanho da playlist a ser redefinida

    for (int i = 0; i < tamanho_pl; i++){ // Remove todos os elementos antigos
        playlist->remove(0);
    }

    if(lista != nullptr){ // Verifica se o ponteiro não é nulo
        tamanho_pl = lista->getTamanho(); // Recebe o tamanho da nova lista

        for (int i = 0; i < tamanho_pl; i++){ // Insere todos os elementos da nova lista na lista original
            playlist->insereFim(*lista->buscaMusicaPos(i));
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
