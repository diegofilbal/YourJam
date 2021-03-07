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

// Construtor cópia
Playlist::Playlist(Playlist const &playlist){
    
    // Inicializa os atributos 
    this->playlist = new Lista;
    this->nome = playlist.nome;
    this->proxima = playlist.proxima;

    // Chama a função sobrecarregada de inserção para copiar as músicas
    insereFim(playlist);

}

// Destrutor
Playlist::~Playlist(){
    delete playlist;
}

// Adiciona uma música no início da playlist
bool Playlist::insereInicio(Musica musica){
    return playlist->insereInicio(musica); // Retorna código retornado pela função da classe Lista
}

// Adiciona uma música no fim da playlist
bool Playlist::insereFim(Musica musica){
    return playlist->insereFim(musica); // Retorna código retornado pela função da classe Lista
}

// Adiciona as músicas presentes em uma playlist recebida por parâmetro à playlist local
bool Playlist::insereFim(Playlist const &playlist){
    return this->playlist->insereFim(*playlist.getLista()); // Retorna código retornado pela função da classe Lista
}

// Adiciona uma música em uma posição específica da playlist
bool Playlist::inserePos(int pos, Musica musica){
    return playlist->inserePos(pos, musica); // Retorna código retornado pela função da classe Lista
}

// Remove uma música em uma posição específica da playlist
bool Playlist::remove(int posicao){
    return playlist->remove(posicao); // Retorna código retornado pela função da classe Lista
}

// Remove uma lista de músicas da playlist
int Playlist::remove(Playlist const &playlist){

    int diferenca = this->playlist->getTamanho(); // Armazena o tamanho inicial da playlist

    this->playlist->remove(*playlist.getLista()); // Remove da playlist local as músicas presentes na playlist recebida

    diferenca -= this->playlist->getTamanho(); // Calcula quantas músicas foram removidas

    return diferenca; // Retorna o número de músicas que foram removidas
}

// Move uma música dentro da playlist
void Playlist::moveMusica(int pos_inicial, int pos_final){

    Musica musica;// Variável a receber as informações da musica a ser movida

    // Copia as informações da música a ser movida
    musica.setNome(playlist->buscaMusicaPos(pos_inicial)->getNome());
    musica.setArtista(playlist->buscaMusicaPos(pos_inicial)->getArtista());

    playlist->remove(pos_inicial); // Remove a música da posição atual
    playlist->inserePos(pos_final, musica); // Insere a música na posição para qual o usuário deseja movê-la
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

// Realiza a união de duas playlists
Playlist* Playlist::operator+(Playlist const &playlist) const{

    // Insere a primeira playlist usando o método sobrecarregado de inserção
    Playlist *playlist_final = new Playlist(*this);

    // Insere a segunda playlist usando o método sobrecarregado de inserção
    playlist_final->insereFim(playlist);

    // Retorna o ponteiro de playlist
    return playlist_final;
}

// Insere todas as músicas da playlist local eum uma nova playlist e adiciona ouma música a ela
Playlist* Playlist::operator+(Musica const &musica) const{

    // Insere a playlist local usando o método sobrecarregado de inserção
    Playlist *playlist_final = new Playlist(*this);

    // Insera a música na última posição da playlist
    playlist_final->insereFim(musica);

    // Retorna o ponteiro de playlist
    return playlist_final;
}

// Retorna uma nova lista contendo os elementos da playlist local que não estão na playlist recebida
Playlist* Playlist::operator-(Playlist const &playlist) const{

    // Insere todas as músicas da playlist local utilizando o método sobrecarregado de inserção
    Playlist* playlist_final = new Playlist(*this);

    // Armazena as músicas para a comparação durante o laço
    Musica musica;

    // Remove da playlist final as músicas que estão na playlist recebid apor parâmetro
    for(int i = playlist_final->playlist->getTamanho() - 1; i >= 0; i--){

        musica = *playlist_final->getLista()->buscaMusicaPos(i);

        if(playlist.getLista()->buscaMusica(musica)){ // Verifica se a música está nas duas playlists
            playlist_final->remove(i); // Remove a música
        }
    }

    return playlist_final;
}

// Retorna uma nova lista contendo os elementos da playlist local que não estão na playlist recebida
Playlist* Playlist::operator-(Musica const &musica) const{

    // Insere todas as músicas da playlist local utilizando o método sobrecarregado de inserção
    Playlist* playlist_final = new Playlist(*this);

    if(playlist_final->getLista()->buscaMusica(musica)){ // Verifica se a música recebida por parâmetro está na playlist
        for(int i = 0; i < playlist_final->getLista()->getTamanho(); i++){ // Percorre a lista e procura a posição em que a música a ser removida está posicionada
            if(playlist_final->getLista()->buscaMusicaPos(i)->getNome() == musica.getNome() && playlist_final->getLista()->buscaMusicaPos(i)->getArtista() == musica.getArtista()){
                playlist_final->remove(i); // Remove a música
            }
        }
    }

    return playlist_final;
}

// Extrai a última música da playlist e armazena na música passada por parâmetro
void Playlist::operator>>(Musica *&musica){

    if(!playlist->getTamanho()){ // Verifica se a lista está vazia
        musica = nullptr;

    }else{
        // Extrai o último elemento da lista para e armazena em música
        musica->setNome(playlist->buscaMusicaPos(playlist->getTamanho() - 1)->getNome());
        musica->setArtista(playlist->buscaMusicaPos(playlist->getTamanho() - 1)->getArtista());

        remove(playlist->getTamanho() - 1); // Remove o último elemento da lista
    }

}

// Insere um uma música na playlist a partir de um ponteiro de Musica
void Playlist::operator<<(Musica *&musica){

    if(musica != nullptr){ // Verifica se a música é nula
        insereFim(*musica); // Insere a música
        delete musica; // Libera espaço de memória da heap
    }

}

// Imprime as músicas da playlist recursivamente
void Playlist::imprime(Node* const node, int contador) const{
    if(node == nullptr){ // Verifica se a lista já chegou ao fim
        return;
    }
    std::cout << contador << ". " << node->musica->getNome() << " - " << node->musica->getArtista() << std::endl;
    imprime(node->next, contador + 1); // Faz a chamada recursiva para a immressão do próximo node 
}

// Retorna a playlist
Lista* Playlist::getLista() const{
    return playlist;
}

// Descarta a lista antiga e faz uma cópia da lista recebida
void Playlist::setLista(Lista* const lista){

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
std::string Playlist::getNome() const{
    return nome;
}
