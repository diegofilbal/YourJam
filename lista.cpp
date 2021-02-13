#include <iostream>
#include <cstring>
#include "musica.hpp"
#include "node.hpp"
#include "lista.hpp"

// Construtor
Lista::Lista(){
    head = nullptr;
    tail = head;
    tamanho = 0;
}

// Destrutor
Lista::~Lista(){

    //  Verifica se a lista já não está vazia
    if(tamanho == 0){
        return;
    }else{
        // Lista não está vazia

        Node* atual = head; // Ponteiro do node que vai percorrer a lista

        while (atual != nullptr){ // Percorre a lista, desalocando cada posição ainda existente
            Node* temp = atual->next;
            delete atual->musica;
            delete atual;
            atual = temp;
        }
    }
}

// Insere uma música no sistema no início da lista
bool Lista::insereInicio(Musica musica){

    if(busca(musica) == nullptr){ // Verifica se a música já está cadastrada
        // A música não está cadastrada no sistema

        Node *temp = new Node;
        temp->musica = new Musica;

        temp->musica->setNome(musica.getNome());
        temp->musica->setArtista(musica.getArtista());
        temp->next = head;
        head = temp;

        if(tamanho == 1){
            tail = temp->next;
        }

        tamanho++;

        return true; // Retorna código de sucesso

    }else{
        return false; // Retorna código de erro
    }
}

// Insere uma música no sistema no fim da lista
bool Lista::insereFim(Musica musica){

    if(busca(musica) == nullptr){ // Verifica se a música já está inserida
        // A música não está cadastrada no sistema
        
        if(head == nullptr){ // Caso a lista esteja vazia
            head = new Node;
            head->musica = new Musica;
            head->musica->setNome(musica.getNome());
            head->musica->setArtista(musica.getArtista());
            head->next = nullptr;
            tail = head;
            tamanho++;

        }else{ // Caso a lista não esteja vazia
            Node *temp = new Node;
            temp->musica = new Musica;
            temp->musica->setNome(musica.getNome());
            temp->musica->setArtista(musica.getArtista());
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
            tamanho++;
        }

        return true; // Retorna código de sucesso

    }else{
        // Música já está inserida no banco de músicas
        return false; // Retorna código de erro
    }
}

// Insere uma música no sistema em uma posição específica
bool Lista::inserePos(int posicao, Musica musica){

    posicao--; // Ajusta a posição para a faixa de valores dos índices (0 -> n-1)

    if(posicao == 0){ // Verifica se é na primeira posição
        if(tamanho == 0){
            return insereFim(musica); // Retorna código retornado pela função chamada
        }else{
            return insereInicio(musica); // Retorna código retornado pela função chamada
        }
    }else{
        if(posicao == tamanho){ // Verifica se é na última posição
            return insereFim(musica); // Retorna código retornado pela função chamada

        }else{
            // A inserção é no meio da lista 

            if(busca(musica) == nullptr){ // Verifica se a música já está cadastrada

                Node* temp = new Node;
                temp->musica = new Musica;
                Node* atual = head;
                Node* anterior = nullptr;

                int contador = 0;

                while (contador < posicao){ // Percorre a lista até alcançar o node da posição desejada
                    anterior = atual;
                    atual = atual->next;                
                    contador++;
                }

                temp->musica->setNome(musica.getNome());
                temp->musica->setArtista(musica.getArtista());
                temp->next = atual;
                anterior->next = temp;
                tamanho++;

                return true; // Retrona código de sucesso
                
            }else{
                return false; // Retorna código de erro
            }       
        }
    }
}

// Remove uma música do sistema pela posição
void Lista::removePos(int posicao){

    Node *atual = head;
    Node *anterior = nullptr;

    for(int i=1;i<posicao;i++){
      anterior=atual;
      atual=atual->next;
    }

    if(atual == head){
        head = head->next;
    }else{
        if(atual == tail){
            anterior->next = nullptr;
            tail = anterior;
        }else{
            anterior->next=atual->next;
        }
    }
        
    tamanho--;
    delete atual->musica;
    delete atual;
}

// Verifica se uma determinada música está cadastrada no sistema (retorna ponteiro de Node)
Node* Lista::busca(Musica musica){

    Node *atual = head; // Objeto a receber os elementos da lista durante as iterações do laço

    while(atual != nullptr){
        if(atual->musica->getNome() == musica.getNome() && atual->musica->getArtista() == musica.getArtista()){
            // Achou a música no sistema
            return atual; // Retorna o ponteiro para o node que armazena a música buscada
        }else{
            atual = atual->next; // Pula para o pŕoximo node
        }
    }

    return nullptr; // A música não está no sistema
}

// Verifica se uma determinada música está cadastrada no sistema por sua posição (retorna ponteiro de Node)
Node* Lista::buscaPos(int posicao){
    // A FAZER
    return nullptr;
}

// Verifica se uma determinada música está cadastrada no sistema (retorna ponteiro de Musica)
Musica* Lista::buscaMusica(Musica musica){
    
    Node *atual = head; // Objeto a receber os elementos da lista durante as iterações do laço

    while(atual != nullptr){
        if(atual->musica->getNome() == musica.getNome() && atual->musica->getArtista() == musica.getArtista()){
            // Achou a música no sistema
            return atual->musica; // Retorna o ponteiro para o node que armazena a música buscada
        }else{
            atual = atual->next; // Pula para o pŕoximo node
        }
    }

    return nullptr; // A música não está no sistema
}

// Verifica se uma determinada música está cadastrada no sistema por sua posição (retorna ponteiro de Musica)
Musica* Lista::buscaMusicaPos(int posicao){
    // A FAZER
    return nullptr;
}

// Imprime todas as músicas da lista
void Lista::imprime(){

    Node *temp = head;

    for(int i = 0; i < tamanho; i++){
        std::cout << i+1 << ". " << temp->musica->getArtista() << " - " << temp->musica->getNome() << std:: endl;
        temp = temp->next;
    }

}

// Retorna o tamanho da lista
int Lista::getTamanho(){
    return tamanho;
}
