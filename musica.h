#ifndef MUSICA_H
#define MUSICA_H

#include <string>

using std::string;

class Musica{

private:
    // Atributos da classe
    string nome, artista;

public:
    // Métodos da classe

    Musica();
    ~Musica();

    string getNome();
    void setNome(string nome);

    string getArtista();
    void setArtista(string artista);

};

#endif