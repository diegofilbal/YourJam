#pragma once

#include <string>

class Musica{

private:
    // Atributos da classe
    std::string nome, artista;

public:
    // Métodos da classe

    Musica();
    ~Musica();

    std::string getNome();
    void setNome(std::string nome);

    std::string getArtista();
    void setArtista(std::string artista);

};