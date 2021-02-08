#include <iostream>
#include "musica.h"

// Construtor
Musica::Musica(){

}

// Destrutor
Musica::~Musica(){
    
}

// Retorna o nome da música
string Musica::getNome(){
    return nome;
}

// Define o nome da música 
void Musica::setNome(string nome){
    this->nome = nome;
}

// Retorna o nome do artista
string Musica::getArtista(){
    return artista;
}

// Define o nome do artista
void Musica::setArtista(string artista){
    this->artista = artista;
}