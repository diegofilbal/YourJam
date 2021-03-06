#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "musica.hpp"
#include "node.hpp"
#include "lista.hpp"
#include "playlist.hpp"

#define MAX_PL 20

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main(int argc, char const *argv[]){

    // Variável para uma flag de condição
    bool flag = false;

    // Variáveis para guardar opções que o usuário escolheu
    int op1 = 0, op2 = 0, op3 = 0, op4 = 0;

    // Variável para quardar a quantidade de playlists cadastradas
    int qtd_pl = 0;

    // Variável para receber a posição da playlist escolhida pelo usuário
    int posicao_pl;

    // Variável para armazenar as posições digitadas pelo usuário
    int posicao1, posicao2;

    // Variáveis para armazenar os nomes das músicas, artistas e playlists
    string nome_musica, nome_artista, nome_playlist;

    // Variável para reber a string das opções do usuário nos menus
    string s_op;

    // Variável para montar uma música ou receber retorno de alguma função
    Musica musica;
    
    // Variável para receber o ponteiro da próxima música a ser tocada
    Musica *prox_musica;

    // Lista de todas as músicas do sistema
    Lista *musicas_sistema = new Lista;

    // Lista de músicas a ser usada em diferentes funções
    Lista lista_temp;

    // Array de todas as playlists
    Playlist *playlists = new Playlist[MAX_PL];

    // Playlist auxiliar a ser usada em diferentes funções
    Playlist playlist_temp;

    //system("clear");

    // Apresentação do menu principal do programa
    do{

        cout << "+---------------------------+" << endl;
        cout << "|      MENU PRINCIPAL       |" << endl;
        cout << "+---------------------------+" << endl;
        cout << "| 1 - Músicas do sistema    |" << endl;
        cout << "| 2 - Playlists             |" << endl;
        cout << "| 3 - Sair                  |" << endl;
        cout << "+---------------------------+" << endl;

        cout << "Digite uma opção: ";

        // Lê a string da opção e converte para inteiro
        getline(cin, s_op);
        std::stringstream op(s_op);
        op >> op1;

        system("clear");

        switch (op1){

            case 1: // Menu de musicas do sistema
                
                do{

                    cout << "+--------------------------------+" << endl;
                    cout << "|       MÚSICAS DO SISTEMA       |" << endl;
                    cout << "+--------------------------------+" << endl;
                    cout << "| 1 - Adicionar música           |" << endl;
                    cout << "| 2 - Adicionar lista de músicas |" << endl;
                    cout << "| 3 - Remover música             |" << endl;
                    cout << "| 4 - Remover lista de músicas   |" << endl;
                    cout << "| 5 - Exibir músicas cadastradas |" << endl;
                    cout << "| 6 - Fazer cópia da lista       |" << endl;
                    cout << "| 7 - Voltar                     |" << endl;
                    cout << "+--------------------------------+" << endl;

                    cout << "Digite uma opção: ";

                    // Lê a string da opção e converte para inteiro
                    getline(cin, s_op); 
                    std::stringstream op(s_op);
                    op >> op2;

                    system("clear");

                    switch(op2){

                        case 1: // Adicionar música

                            fflush(stdin); // Limpa o buffer
                            cout << "Digite o nome da música: ";
                            getline(cin, nome_musica);

                            fflush(stdin); // Limpa o buffer
                            cout << "\nDigite o nome do artista: ";
                            getline(cin, nome_artista);

                            // Monta a música
                            musica.setNome(nome_musica);
                            musica.setArtista(nome_artista);

                            cout << "\nDeseja incluir em alguma posição específica? Não(1) ou Sim(2): ";
                            cin >> op3;
                            cin.ignore();

                            if(op3 == 2){ // Verifica se o usuário deseja inserir em uma posição específica

                                system("clear");

                                musicas_sistema->imprime(); // Imprime a lista de músicas do sistema

                                cout << "\nDigite a posição: ";
                                cin >> posicao1;
                                cin.ignore();

                                if(posicao1 > musicas_sistema->getTamanho() + 1){ // Verifica se a posição é válida
                                    cout << "\nPosição inválida!" << endl;

                                }else{
                                    if(musicas_sistema->inserePos(posicao1 - 1, musica)){ // Chama a função e verifica se a inserção foi bem sucedida
                                        cout << "\nMúsica cadastrada no sistema com sucesso!" << endl;

                                    }else{
                                        cout << "\nErro ao cadastrar música no sistema!" << endl;
                                    }
                                }

                            }else{
                                if(op3 == 1){ // Verifica se o usuário não quer inserir em uma posição específica
                                    if(musicas_sistema->insereFim(musica)){ // Verifica se a inserção foi bem sucedida
                                        cout << "\nMúsica cadastrada no sistema com sucesso!" << endl;

                                    }else{
                                        cout << "\nErro ao cadastrar música no sistema!" << endl;
                                    }

                                }else{
                                    cout << "\nOpção inválida!" << endl;
                                }
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 2: // Adicionar lista de música
                            
                            // Monta e insere as músicas na lista temporária
                            musica.setNome("Pra Animar o Bar");
                            musica.setArtista("Cícero");
                            lista_temp.insereFim(musica);

                            musica.setNome("What's Going On");
                            musica.setArtista("Marvin Gaye");
                            lista_temp.insereFim(musica);

                            musica.setNome("Heartbreak Anniversary");
                            musica.setArtista("Giveon");
                            lista_temp.insereFim(musica);

                            cout << "Lista de músicas a serem inseridas no sistema:" << endl;
                            lista_temp.imprime();
                            cout << endl;

                            if(musicas_sistema->insereFim(lista_temp)){ // Verifica se a inserção foi bem sucedida
                                cout << "\nMúsicas cadastradas com sucesso!" << endl;
                            }
                            else{
                                cout << "\nErro ao cadastrar lista de músicas" << endl;
                            }

                            for(int i = lista_temp.getTamanho() - 1; i >= 0; i--){ // Limpa a lista temporária
                                lista_temp.remove(i);
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 3: // Remover música

                            if(musicas_sistema->getTamanho() > 0){ // Verifica se há músicas cadastradas
                                
                                musicas_sistema->imprime(); // Imprime a lista de músicas para o usuário
                                
                                cout << "\nDigite o número da música que deseja remover do sistema: ";
                                cin >> posicao1;
                                cin.ignore();

                                if(posicao1 >= 1 && posicao1 <= musicas_sistema->getTamanho()){ // Verifica se a posição digitada é válida

                                    musica = *(musicas_sistema->buscaMusicaPos(posicao1 - 1)); // Recebe a música da posição especificada

                                    for(int i = 0; i < qtd_pl; i++){ // Laço para percorrer o array de playlists procurando por playlists com a música a ser apagada
                                        if(playlists[i].getLista()->buscaMusica(musica) != nullptr){
                                            for(int j = 0; j < playlists[i].getLista()->getTamanho(); j++){ // Percorre os elementos da playlist para achar a posição da música a ser apagada
                                                if(playlists[i].getLista()->buscaMusicaPos(j)->getNome() == musica.getNome() && playlists[i].getLista()->buscaMusicaPos(j)->getArtista() == musica.getArtista()){
                                                    if(playlists[i].remove(j)){ // Verifica se a remoção foi bem sucedida
                                                        cout << "\nA música " << musica.getNome() << " de " << musica.getArtista() << " estava na posição " << j+1 <<  " da playlist " << playlists[i].getNome() << " e foi removida!";
                                                    
                                                    }else{
                                                        cout << "\nErro ao remover a música " << musica.getNome() << " de " << musica.getArtista() << " da playlist " << playlists[i].getNome() << "!" << endl;
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    if(musicas_sistema->remove(posicao1 - 1)){ // Verifica se houve sucesso na remoção da música
                                        cout << "\nMúsica removida do sistema com sucesso!" << endl;
                                        
                                    }else{
                                        cout << "\nErro ao remover música!" << endl;
                                    }

                                }else{
                                    cout << "\nPosição inválida!" << endl;
                                }

                            }else{
                                cout << "Não há músicas cadastradas no sistema!" << endl << endl;
                            }
                            
                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 4: // Remover lista de músicas

                            // Monta e insere as músicas na lista temporária
                            musica.setNome("Heartbreak Anniversary");
                            musica.setArtista("Giveon");
                            lista_temp.insereFim(musica);

                            musica.setNome("Pra Animar o Bar");
                            musica.setArtista("Cícero");
                            lista_temp.insereFim(musica);

                            musica.setNome("What's Going On");
                            musica.setArtista("Marvin Gaye");
                            lista_temp.insereFim(musica);

                            cout << "Lista de músicas a serem removidas do sistema:" << endl;
                            lista_temp.imprime();
                            cout << endl;

                            for(int i = 0; i < lista_temp.getTamanho(); i++){ // Percorre a lista de músicas a serem remmovidas

                                musica = *lista_temp.buscaMusicaPos(i); // Recebe as músicas da lista temporária
                                
                                for(int j = 0; j < qtd_pl; j++){ // Laço para percorrer o array de playlists procurando por playlists com a música a ser apagada
                                    if(playlists[j].getLista()->buscaMusica(musica) != nullptr){
                                        for(int k = 0; k < playlists[j].getLista()->getTamanho(); k++){ // Percorre os elementos da playlist para achar a posição da música a ser apagada
                                            if(playlists[j].getLista()->buscaMusicaPos(k)->getNome() == musica.getNome() && playlists[j].getLista()->buscaMusicaPos(k)->getArtista() == musica.getArtista()){
                                                if(playlists[j].remove(k)){ // Verifica se a remoção foi bem sucedida
                                                    cout << "A música " << musica.getNome() << " de " << musica.getArtista() << " estava na playlist " << playlists[j].getNome() << " e foi removida!" << endl;
                                                
                                                }else{
                                                    cout << "Erro ao remover a música " << musica.getNome() << " de " << musica.getArtista() << " da playlist " << playlists[j].getNome() << "!" << endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            if(musicas_sistema->remove(lista_temp)){ // Verifica se a remoção foi bem sucedida
                                cout << "Músicas removidas com sucesso!" << endl;

                            }else{
                                cout << "Erro ao remover músicas!" << endl;
                            }

                            for(int i = lista_temp.getTamanho() - 1; i >= 0; i--){ // Limpa a lista temporária
                                lista_temp.remove(i);
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                            
                        case 5: // Exibir músicas cadastradas

                            if(musicas_sistema->getTamanho() > 0){ // Verifica se há músicas cadastradas
                                musicas_sistema->imprime(); // Imprime a lista de músicas para o usuário
                                cout << endl;

                            }else{
                                cout << "Não há músicas cadastradas no sistema!" << endl << endl;
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 6: // Fazer cópia da lista
                            
                            if(musicas_sistema->getTamanho() > 0){ // Verifica se a lista do sistema não está vazia

                                Lista lista_temp2(*musicas_sistema); // Declara a lista temporária utilizando o construtor cópia
                                
                                // Imprime as listas informando seus endereços na memória
                                cout << "Lista original de músicas do sistema: (Endereço da lista: " << musicas_sistema << ")" << endl;
                                for(int i = 0; i < musicas_sistema->getTamanho(); i++){
                                    cout << i + 1 << ". " << musicas_sistema->buscaMusicaPos(i)->getNome() << " - " << musicas_sistema->buscaMusicaPos(i)->getArtista() << " (Endereço da música: " << musicas_sistema->buscaMusicaPos(i) << ")" << endl;
                                }

                                cout << endl << "Lista cópia de músicas do sistema: (Endereço da lista: " << &lista_temp2 << ")" << endl;
                                for(int i = 0; i < lista_temp2.getTamanho(); i++){
                                    cout << i + 1 << ". " << lista_temp2.buscaMusicaPos(i)->getNome() << " - " << lista_temp2.buscaMusicaPos(i)->getArtista() << " (Endereço da música: " << lista_temp2.buscaMusicaPos(i) << ")" << endl;
                                }

                                for(int i = lista_temp.getTamanho() - 1; i >= 0; i--){ // Limpa a lista temporária
                                    lista_temp2.remove(i);
                                }

                                cout << endl;

                            }else{
                                cout << "Não há músicas cadastradas no sistema!" << endl << endl;
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 7: break; // Sair

                        default: // Opção inválida
                            cout << "Opção inválida!" << endl;
                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");
                            break;
                    }

                }while (op2 != 7);

                break;

            case 2: // Menu de playlists
                                
                do{

                    cout << "+------------------------+" << endl;
                    cout << "|       PLAYLISTS        |" << endl;
                    cout << "+------------------------+" << endl;
                    cout << "| 1 - Adicionar playlist |" << endl;
                    cout << "| 2 - Remover playlist   |" << endl;
                    cout << "| 3 - Exibir playlists   |" << endl;
                    cout << "| 4 - Abrir uma playlist |" << endl;
                    cout << "| 5 - Voltar             |" << endl;
                    cout << "+------------------------+" << endl;

                    cout << "Digite uma opção: ";

                    // Lê a string da opção e converte para inteiro
                    getline(cin, s_op); 
                    std::stringstream op(s_op); 
                    op >> op2;

                    system("clear");

                    switch(op2){
                        case 1: // Adicionar playlist

                            if(qtd_pl < MAX_PL){ // Verifica se o número máximo de playlists permitidas já foi atingido
                                
                                fflush(stdin); // Limpa o buffer
                                cout << "Digite o nome da playlist que deseja inserir: ";
                                getline(cin, nome_playlist);
                                
                                flag = false;
                                for(int i = 0; i < qtd_pl; i++){ // Verifica se há uma playlist com o mesmo nome
                                    if(nome_playlist == playlists[i].getNome()){
                                        flag = true;
                                    }
                                }

                                if(!flag){
                                    // A playlist não existe e pode ser adicionada
                                    playlists[qtd_pl].setNome(nome_playlist);
                                    cout << "\nPlaylist " << playlists[qtd_pl].getNome() << " adicionada com sucesso!" << endl;
                                    qtd_pl++;

                                }else{
                                    cout << "\nEsta playlist já existe!" << endl;
                                }

                            }else{
                                cout << "Você já atingiu o limite de playlists!" << endl << endl;
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 2: // Remover playlist

                            if(qtd_pl > 0){ // Verifica se há playlists cadastradas

                                for(int i = 0; i < qtd_pl; i++){ // Exibe as playlists cadastradas
                                    cout << i+1 << ". " << playlists[i].getNome() << endl;
                                }

                                cout << "\nDigite o número da playlist que deseja remover: ";
                                cin >> posicao1;
                                cin.ignore();

                                if(posicao1 >= 1 && posicao1 <= qtd_pl){ // Verifica se a posição é válida

                                    posicao1--; // Ajusta a posição para a faixa de valores dos índices (0 -> n-1)
                                    
                                    for(int i = posicao1; i < qtd_pl - 1; i++){ // Percorre o array realocando as posições
                                        playlists[i].setNome(playlists[i + 1].getNome());
                                        playlists[i].setLista(playlists[i + 1].getLista());
                                    }

                                    playlists[qtd_pl - 1].setNome("");
                                    playlists[qtd_pl - 1].setLista(nullptr);

                                    qtd_pl--; // Atualiza o tamanho da playlist

                                    cout << "\nPlaylist removida com sucesso!" << endl;

                                }else{
                                    cout << "\nPosição inválida!" << endl;
                                }

                            }else{
                                cout << "Não há nenhuma playlist cadastrada!" << endl << endl;
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 3: // Exibe as playlists cadastradas

                            if(qtd_pl > 0){
                                for(int i = 0; i < qtd_pl; i++){ // Imprime o nome das playlists
                                    cout << i+1 << ". " << playlists[i].getNome() << endl;
                                }
                                cout << endl;

                            }else{
                                cout << "Não há nenhuma playlist cadastrada!" << endl << endl;
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 4: // Abrir uma playlist

                            if(qtd_pl > 0){ // Verifica se há playlists cadastradas

                                for(int i = 0; i < qtd_pl; i++){ // Imprime o nome das playlists
                                    cout << i+1 << ". " << playlists[i].getNome() << endl;
                                }

                                do{
                                    cout << "\nDigite o número da playlist que deseja abrir: ";
                                    cin >> posicao_pl;
                                    cin.ignore();
                                    if(posicao_pl < 1 || posicao_pl > qtd_pl){
                                        cout << "Playlist inválida! Escolha novamente!" << endl;
                                    }
                                }while(posicao_pl < 1 || posicao_pl > qtd_pl);

                                posicao_pl--; // Adequa a variável à faixa de números de índices (0 -> n-1)

                                system("clear");

                                do{

                                    cout << "+--------------------------------+" << endl;
                                    cout << "|      MÚSICAS DA PLAYLIST       |" << endl;
                                    cout << "+--------------------------------+" << endl;
                                    cout << "| 1 - Adicionar música           |" << endl;
                                    cout << "| 2 - Adicionar lista de músicas |" << endl;
                                    cout << "| 3 - Remover música             |" << endl;
                                    cout << "| 4 - Remover lista de músicas   |" << endl;
                                    cout << "| 5 - Mover música               |" << endl;
                                    cout << "| 6 - Exibir músicas da playlist |" << endl;
                                    cout << "| 7 - Reproduzir playlist        |" << endl;
                                    cout << "| 8 - Voltar                     |" << endl;
                                    cout << "+--------------------------------+" << endl;

                                    cout << "Digite uma opção: ";

                                    // Lê a string da opção e converte para inteiro
                                    getline(cin, s_op);
                                    std::stringstream op(s_op);
                                    op >> op3;

                                    system("clear");

                                    switch(op3){

                                        case 1: // Adicionar música

                                            if(musicas_sistema->getTamanho() > 0){ // Verfica se há músicas no sistema

                                                // Imprime as músicas do sistema
                                                musicas_sistema->imprime();

                                                cout << "\nDigite a posição da música que deseja adicionar em " << playlists[posicao_pl].getNome() << ": ";
                                                cin >> posicao1;
                                                cin.ignore();

                                                if(posicao1 > 0 && posicao1 <= musicas_sistema->getTamanho()){ // Verifica se a posição é válida

                                                    musica = *musicas_sistema->buscaMusicaPos(posicao1 - 1);

                                                    if(playlists[posicao_pl].getLista()->buscaMusica(musica) == nullptr){ // Verifica se a música já existe na playlist

                                                        cout << "\nDeseja adicionar esta música em uma posição específica de " << playlists[posicao_pl].getNome() << "? Não(1) ou Sim(2): ";
                                                        cin >> op4;
                                                        cin.ignore();

                                                        if(op4 == 1){
                                                            // Insere no final
                                                            if(playlists[posicao_pl].insereFim(musica)){ // Verifica se a inserção foi bem sucedida
                                                                cout << "\nMúsica adicionada na playlist com sucesso!" << endl;

                                                            }else{
                                                                cout << "\nErro ao adicionar música na playlist!" << endl;
                                                            }

                                                        }else{
                                                            // Insere em uma posição específica
                                                            system("clear");
                                                            
                                                            playlists[posicao_pl].imprime(playlists[posicao_pl].getLista()->buscaPos(0), 1); // Imprime as músicas da playlist

                                                            cout << "\nDigite a posição em que deseja inserir a música: ";
                                                            cin >> posicao2;
                                                            cin.ignore();

                                                            if(posicao2 > 0 && posicao2 <= playlists[posicao_pl].getLista()->getTamanho()){ // Verifica se a posição é válida
                                                                if(playlists[posicao_pl].inserePos(posicao2 - 1, musica)){ // Verifica se a inserção foi bem sucedida
                                                                    cout << "\nMúsica adicionada na playlist com sucesso!" << endl;
                                                                
                                                                }else{
                                                                    cout << "\nErro ao adicionar música na playlist!" << endl;
                                                                }

                                                            }else{
                                                                cout << "\nPosição inválida!" << endl;
                                                            }
                                                        }

                                                    }else{
                                                        cout << "\nEsta música já está na playlist!" << endl;
                                                    }

                                                }else{
                                                    cout << "\nPosição inválida!" << endl;
                                                }

                                            }else{
                                                cout << "Não há músicas cadastradas no sistema!" << endl << endl;
                                            }

                                            cout << "Pressione ENTER para continuar..." << endl;
                                            getchar();
                                            system("clear");

                                            break;
                                        
                                        case 2: // Adicionar lista de músicas

                                            // Monta e insere músicas na playlist temporária
                                            playlist_temp.setNome("Playlist temporária");

                                            musica.setNome("Runaway");
                                            musica.setArtista("AURORA");
                                            playlist_temp.insereFim(musica);

                                            musica.setNome("No Title");
                                            musica.setArtista("Corbin");
                                            playlist_temp.insereFim(musica);

                                            musica.setNome("Time Machine");
                                            musica.setArtista("WILLOW");
                                            playlist_temp.insereFim(musica);

                                            cout << "Lista de músicas a serem inseridas na playlist:" << endl;
                                            playlist_temp.imprime(playlist_temp.getLista()->buscaPos(0), 1);
                                            cout << endl;

                                            if(playlists[posicao_pl].insereFim(playlist_temp)){ // Verifica se a inserção foi bem sucedida
                                                cout << "\nMúsicas adicionadas com sucesso!" << endl;
                                            }else{
                                                cout << "\nErro ao adicionar músicas à playlist!" << endl;
                                            }

                                            for(int i = playlist_temp.getLista()->getTamanho() - 1; i >= 0; i--){ // Limpa a playlist temporária
                                                playlist_temp.remove(i);
                                            }

                                            cout << "Pressione ENTER para continuar..." << endl;
                                            getchar();
                                            system("clear");

                                            break;

                                        case 3: // Remover música

                                            if(playlists[posicao_pl].getLista()->getTamanho() > 0){ // Verifica se há músicas cadastradas

                                                playlists[posicao_pl].imprime(playlists[posicao_pl].getLista()->buscaPos(0), 1); // Imprime a lista de músicas da playlist para o usuário
                                                
                                                cout << "\nDigite o número da música que deseja remover da playlist: ";
                                                cin >> posicao1;
                                                cin.ignore();

                                                if(posicao1 >= 1 && posicao1 <= playlists[posicao_pl].getLista()->getTamanho()){ // Verifica se a posição digitada é válida
                                                    if(playlists[posicao_pl].remove(posicao1 - 1)){ // Verifica se a remoção foi bem sucedida
                                                        cout << "\nMúsica removida com sucesso!" << endl;

                                                    }else{
                                                        cout << "\nErro ao remover música!" << endl;
                                                    }

                                                }else{
                                                    cout << "\nPosição inválida!" << endl;
                                                }

                                            }else{
                                                cout << "Não há músicas para remover!" << endl << endl;
                                            }

                                            cout << "Pressione ENTER para continuar..." << endl;
                                            getchar();
                                            system("clear");

                                            break;

                                        case 4: // Remover uma lista de músicas da playlist aberta
                                            
                                            // Monta e insere músicas na playlist temporária
                                            playlist_temp.setNome("Playlist temporária");

                                            musica.setNome("Runaway");
                                            musica.setArtista("AURORA");
                                            playlist_temp.insereFim(musica);

                                            musica.setNome("No Title");
                                            musica.setArtista("Corbin");
                                            playlist_temp.insereFim(musica);

                                            musica.setNome("Time Machine");
                                            musica.setArtista("WILLOW");
                                            playlist_temp.insereFim(musica);

                                            cout << "Lista de músicas a serem removidas na playlist:" << endl;
                                            playlist_temp.imprime(playlist_temp.getLista()->buscaPos(0), 1);
                                            cout << endl << endl;

                                            cout << playlists[posicao_pl].remove(playlist_temp) << " músicas foram removidas da playlist!" << endl;

                                            for(int i = playlist_temp.getLista()->getTamanho() - 1; i >= 0; i--){ // Limpa a playlist temporária
                                                playlist_temp.remove(i);
                                            }

                                            cout << "Pressione ENTER para continuar..." << endl;
                                            getchar();
                                            system("clear");

                                            break;

                                        case 5: // Mover música

                                            if(playlists[posicao_pl].getLista()->getTamanho() > 0){ // Verifica se há música na playlist

                                                if(playlists[posicao_pl].getLista()->getTamanho() > 1){ // Verifica se é possível mover músicas de lugar

                                                    playlists[posicao_pl].imprime(playlists[posicao_pl].getLista()->buscaPos(0), 1);
                                                    cout << endl;

                                                    cout << "Digite a posição atual da música que deseja mover: ";
                                                    cin >> posicao1;
                                                    cin.ignore();

                                                    if(posicao1 > 0 && posicao1 <= playlists[posicao_pl].getLista()->getTamanho()){ // Verifica se a posição é válida
                                                        cout << "Digite a posição para qual deseja mover: ";
                                                        cin >> posicao2;
                                                        cin.ignore();

                                                        if(posicao2 > 0 && posicao2 <= playlists[posicao_pl].getLista()->getTamanho()){ // Verifica se a posição é válida

                                                            playlists[posicao_pl].moveMusica(posicao1 - 1, posicao2 - 1); // Move a música de lugar

                                                            system("clear");

                                                            cout << "Música movida com sucesso!" << endl << endl;

                                                            playlists[posicao_pl].imprime(playlists[posicao_pl].getLista()->buscaPos(0), 1); // Imprime nova organização das músicas
                                                            cout << endl;

                                                        }else{
                                                            cout << "\nPosição inválida!" << endl;
                                                        }

                                                    }else{
                                                        cout << "\nPosição inválida!" << endl;
                                                    }

                                                }else{
                                                    cout << "Não há como mover músicas de lugar pois a playlist só tem uma música!" << endl << endl;
                                                }

                                            }else{
                                                cout << "Não há músicas nessa playlist!" << endl << endl;
                                            }

                                            cout << "Pressione ENTER para continuar..." << endl;
                                            getchar();
                                            system("clear");

                                            break;
                                        
                                        case 6: // Exibir músicas da playlist

                                            if(playlists[posicao_pl].getLista()->getTamanho() > 0){ // Verifica se há músicas na playlist
                                                playlists[posicao_pl].imprime(playlists[posicao_pl].getLista()->buscaPos(0), 1); // Imprime as músicas da playlist
                                                cout << endl;

                                            }else{
                                                cout << "Não há nenhuma música nessa playlist!" << endl << endl;
                                            }

                                            cout << "Pressione ENTER para continuar..." << endl;
                                            getchar();
                                            system("clear");

                                            break;

                                        case 7: // Tocar música

                                            if(playlists[posicao_pl].getLista()->getTamanho() > 0){ // Verifica se a playlist tem músicas cadastradas

                                                system("clear");

                                                prox_musica = playlists[posicao_pl].proxMusica(); // Chama a função e recebe o ponteiro de música

                                                if(prox_musica != nullptr){ // Verifica se a reprodução das músicas já chegou ao fim
                                                    cout << "Tocando " << prox_musica->getNome() << " - " << prox_musica->getArtista() << " da playlist " << playlists[posicao_pl].getNome() << "!" << endl << endl;

                                                }else{
                                                    cout << "Você terminou de escutar essa playlist!" << endl << endl;
                                                }

                                            }else{
                                                cout << "Não há nenhuma música nessa playlist para tocar!" << endl << endl;
                                            }

                                            cout << "Pressione ENTER para continuar..." << endl;
                                            getchar();
                                            system("clear");

                                            break;

                                        case 8: break; // Sair
                                            
                                        default:
                                            cout << "Opção inválida!" << endl;
                                            cout << "Pressione ENTER para continuar..." << endl;
                                            getchar();
                                            system("clear");
                                            break;
                                    }

                                }while (op3 != 8);

                            }else{
                                cout << "Nenhuma playlist cadastrada!\nAdicione uma playlist em \"Playlists\" no Menu Principal!" << endl << endl;
                                cout << "Pressione ENTER para continuar..." << endl;
                                getchar();
                                system("clear");
                            }

                            break;

                        case 5: break; // Sair

                        default:
                            cout << "Opção inválida!" << endl;
                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");
                            break;
                    }

                }while (op2 != 5);

                break;

            case 3: break; // Sair

            default: // Opção inválida
                cout << "Opção inválida!" << endl;
                cout << "Pressione ENTER para continuar..." << endl;
                getchar();
                system("clear");
                break;
        }

    }while(op1 != 3);

    cout << "Programa encerrado!" << endl << endl;

    // Libera os espaços de memória alocados dinamicamente para as músicas do sistema e para as playlists
    delete musicas_sistema;
    //delete lista_temp;
    delete[] playlists;

    return 0;
}