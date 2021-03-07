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

    std::string getNome() const;
    void setNome(std::string const nome);

    std::string getArtista() const;
    void setArtista(std::string const artista);

};