#pragma once

#include<string>
#include "musica.hpp"

class Node{

public:
    // Atributos da classe
    Musica* musica;
    Node* next;

    // Métodos da classe
    Node();
    ~Node();
};