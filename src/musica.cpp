#include <iostream>
#include "musica.hpp"

// Construtor
Musica::Musica(){

}

// Destrutor
Musica::~Musica(){
    
}

// Retorna o nome da música
std::string Musica::getNome(){
    return nome;
}

// Define o nome da música 
void Musica::setNome(std::string nome){
    this->nome = nome;
}

// Retorna o nome do artista
std::string Musica::getArtista(){
    return artista;
}

// Define o nome do artista
void Musica::setArtista(std::string artista){
    this->artista = artista;
}