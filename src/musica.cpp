#include <iostream>
#include "musica.hpp"

// Construtor
Musica::Musica(){

}

// Destrutor
Musica::~Musica(){
    
}

// Retorna o nome da música
std::string Musica::getNome() const{
    return nome;
}

// Define o nome da música 
void Musica::setNome(std::string const nome){
    this->nome = nome;
}

// Retorna o nome do artista
std::string Musica::getArtista() const{
    return artista;
}

// Define o nome do artista
void Musica::setArtista(std::string const artista){
    this->artista = artista;
}