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
using std::stringstream;

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

    // Listas de músicas a serem usadas em diferentes funções
    Lista lista_temp, lista_temp2, *lista_temp3;

    // Array de todas as playlists
    Playlist *playlists = new Playlist[MAX_PL];

    // Playlists auxiliares a serem usadas em diferentes funções
    Playlist playlist_temp, playlist_temp2, *playlist_temp3;

    //system("clear");

    // Apresentação do menu principal do programa
    do{

        cout << "+-----------------------------+" << endl;
        cout << "|        MENU PRINCIPAL       |" << endl;
        cout << "+-----------------------------+" << endl;
        cout << "| 1 - Músicas do sistema      |" << endl;
        cout << "| 2 - Playlists               |" << endl;
        cout << "| 3 - Funções sobrecarregadas |" << endl;
        cout << "|                             |" << endl;
        cout << "+-----------------------------+" << endl;
        cout << "| 4 - Sair                    |" << endl;
        cout << "+-----------------------------+" << endl;

        cout << "Digite uma opção: ";

        // Lê a string da opção e converte para inteiro
        getline(cin, s_op);
        stringstream op(s_op);
        op >> op1;

        system("clear");

        switch (op1){

            case 1: // Menu de musicas do sistema
                
                do{

                    cout << "+--------------------------------+" << endl;
                    cout << "|       MÚSICAS DO SISTEMA       |" << endl;
                    cout << "+--------------------------------+" << endl;
                    cout << "| 1 - Adicionar música           |" << endl;
                    cout << "| 2 - Remover música             |" << endl;
                    cout << "| 3 - Exibir músicas cadastradas |" << endl;
                    cout << "|                                |" << endl;
                    cout << "+--------------------------------+" << endl;
                    cout << "| 4 - Voltar                     |" << endl;
                    cout << "+--------------------------------+" << endl;

                    cout << "Digite uma opção: ";

                    // Lê a string da opção e converte para inteiro
                    getline(cin, s_op); 
                    stringstream op(s_op);
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

                                if(posicao1 > 0 && posicao1 <= musicas_sistema->getTamanho() + 1){ // Verifica se a posição é válida
                                    if(musicas_sistema->inserePos(posicao1 - 1, musica)){ // Chama a função e verifica se a inserção foi bem sucedida
                                        cout << "\nMúsica cadastrada no sistema com sucesso!" << endl;
                                    
                                    }else{
                                        cout << "\nErro ao cadastrar música no sistema!" << endl;
                                    }

                                }else{
                                    cout << "\nPosição inválida!" << endl;
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
                        
                        case 2: // Remover música

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
                        
                        case 3: // Exibir músicas cadastradas

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
                        
                        case 4: break; // Sair

                        default: // Opção inválida
                            cout << "Opção inválida!" << endl;
                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");
                            break;
                    }

                }while (op2 != 4);

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
                    cout << "|                        |" << endl;
                    cout << "+------------------------+" << endl;
                    cout << "| 5 - Voltar             |" << endl;
                    cout << "+------------------------+" << endl;

                    cout << "Digite uma opção: ";

                    // Lê a string da opção e converte para inteiro
                    getline(cin, s_op); 
                    stringstream op(s_op); 
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
                                        break;
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
                                    cout << "| 2 - Remover música             |" << endl;
                                    cout << "| 3 - Mover música               |" << endl;
                                    cout << "| 4 - Exibir músicas da playlist |" << endl;
                                    cout << "| 5 - Reproduzir playlist        |" << endl;
                                    cout << "|                                |" << endl;
                                    cout << "+--------------------------------+" << endl;
                                    cout << "| 6 - Voltar                     |" << endl;
                                    cout << "+--------------------------------+" << endl;

                                    cout << "Digite uma opção: ";

                                    // Lê a string da opção e converte para inteiro
                                    getline(cin, s_op);
                                    stringstream op(s_op);
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
                                                            
                                                            if(playlists[posicao_pl].getLista()->getTamanho() > 0){ // Verifica se a playlist não está vazia
                                                                playlists[posicao_pl].imprime(playlists[posicao_pl].getLista()->buscaPos(0), 1); // Imprime as músicas da playlist
                                                            }else{
                                                                cout << "A playlist está vazia!" << endl;
                                                            }

                                                            cout << "\nDigite a posição em que deseja inserir a música: ";
                                                            cin >> posicao2;
                                                            cin.ignore();

                                                            if(posicao2 > 0 && posicao2 <= playlists[posicao_pl].getLista()->getTamanho() + 1){ // Verifica se a posição é válida
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
                                        
                                        case 2: // Remover música

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

                                        case 3: // Mover música

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
                                        
                                        case 4: // Exibir músicas da playlist

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

                                        case 5: // Reproduzir playlist

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

                                        case 6: break; // Sair

                                        default:
                                            cout << "Opção inválida!" << endl;
                                            cout << "Pressione ENTER para continuar..." << endl;
                                            getchar();
                                            system("clear");
                                            break;
                                    }

                                }while (op3 != 6);

                            }else{
                                cout << "Nenhuma playlist cadastrada!" << endl;
                                cout << "Adicione uma playlist em \"Playlists\" no Menu Principal!" << endl << endl;
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

            case 3: // Menu de testes de funções sobrecarregadas

                do{
                    cout << "+--------------------------------------------+" << endl;
                    cout << "|      TESTE DE FUNÇÕES SOBRECARREGADAS      |" << endl;
                    cout << "+--------------------------------------------+" << endl;
                    cout << "| Novos métodos (Classe Lista)               |" << endl;
                    cout << "| 1 - Adicionar elementos (1.A)              |" << endl;
                    cout << "| 2 - Remover elementos (1.B)                |" << endl;
                    cout << "| 3 - Construtor cópia (1.C)                 |" << endl;
                    cout << "|                                            |" << endl;
                    cout << "| Sobrecarga de operadores (Classe Lista)    |" << endl;
                    cout << "| 4 - Operador \"+\" (2.A)                     |" << endl;
                    cout << "| 5 - Operador de extração \">>\" (2.B)        |" << endl;
                    cout << "| 6 - Operador de inserção \"<<\" (2.C)        |" << endl;
                    cout << "|                                            |" << endl;
                    cout << "| Novos métodos (Classe Playlist)            |" << endl;
                    cout << "| 7 - Adicionar músicas (3.A)                |" << endl;
                    cout << "| 8 - Remover músicas (3.B)                  |" << endl;
                    cout << "| 9 - Construtor cópia (3.C)                 |" << endl;
                    cout << "|                                            |" << endl;
                    cout << "| Sobrecarga de operadores (Classe Playlist) |" << endl;
                    cout << "| 10 - Operador \"+\" versão 1 (4.A)           |" << endl;
                    cout << "| 11 - Operador \"+\" versão 2 (4.B)           |" << endl;
                    cout << "| 12 - Operador \"-\" versão 1 (4.C)           |" << endl;
                    cout << "| 13 - Operador \"-\" versão 2 (4.D)           |" << endl;
                    cout << "| 14 - Operador de extração \">>\" (4.E)       |" << endl;
                    cout << "| 15 - Operador de inserção \"<<\" (4.F)       |" << endl;
                    cout << "|                                            |" << endl;
                    cout << "+--------------------------------------------+" << endl;
                    cout << "| 16 - Voltar                                |" << endl;
                    cout << "+--------------------------------------------+" << endl;

                    cout << "Digite uma opção: ";

                    // Lê a string da opção e converte para inteiro
                    getline(cin, s_op);
                    stringstream op(s_op);
                    op >> op2;

                    system("clear");

                    switch (op2){

                        case 1: // Adicionar elementos (1.A)

                            // Monta e insere as músicas na lista inicial
                            musica.setNome("Pra Animar o Bar");
                            musica.setArtista("Cícero");
                            lista_temp.insereFim(musica);

                            musica.setNome("What's Going On");
                            musica.setArtista("Marvin Gaye");
                            lista_temp.insereFim(musica);

                            musica.setNome("Heartbreak Anniversary");
                            musica.setArtista("Giveon");
                            lista_temp.insereFim(musica);

                            // Imprime a lista incial
                            cout << "Lista inicial: " << endl;
                            lista_temp.imprime();
                            cout << endl;

                            // Monta e insere as músicas na lista de músicas a serem inseridas
                            musica.setNome("What's Going On");
                            musica.setArtista("Marvin Gaye");
                            lista_temp2.insereFim(musica);

                            musica.setNome("Dyade");
                            musica.setArtista("Flavien Berger");
                            lista_temp2.insereFim(musica);

                            musica.setNome("Sin City");
                            musica.setArtista("Black Atlas");
                            lista_temp2.insereFim(musica);

                            // Imprime a lista de músicas a serem inseridas
                            cout << "Lista de músicas a serem inseridas:" << endl;
                            lista_temp2.imprime();
                            cout << endl;

                            if(lista_temp.insereFim(lista_temp2)){ // Verifica se a inserção foi bem sucedida
                                cout << endl << "Lista inicial após inserção: " << endl;
                                lista_temp.imprime();
                                cout << endl << "Músicas inseridas com sucesso!" << endl;

                            }else{
                                cout << "Erro ao inserir lista de músicas" << endl;
                            }

                            // Limpa as listas temporárias
                            for(int i = lista_temp.getTamanho() - 1; i >= 0; i--){
                                lista_temp.remove(i);
                            }

                            for(int i = lista_temp2.getTamanho() - 1; i >= 0; i--){
                                lista_temp2.remove(i);
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 2: // Remover elementos (1.B)
                            
                            // Monta e insere as músicas na lista inicial
                            musica.setNome("Pra Animar o Bar");
                            musica.setArtista("Cícero");
                            lista_temp.insereFim(musica);

                            musica.setNome("What's Going On");
                            musica.setArtista("Marvin Gaye");
                            lista_temp.insereFim(musica);

                            musica.setNome("Heartbreak Anniversary");
                            musica.setArtista("Giveon");
                            lista_temp.insereFim(musica);

                            // Imprime a lista incial
                            cout << "Lista inicial: " << endl;
                            lista_temp.imprime();
                            cout << endl;

                            // Monta e insere as músicas na lista de músicas a serem removidas
                            musica.setNome("What's Going On");
                            musica.setArtista("Marvin Gaye");
                            lista_temp2.insereFim(musica);

                            musica.setNome("Better Together");
                            musica.setArtista("Jack Johnson");
                            lista_temp2.insereFim(musica);

                            // Imprime a lista de músicas a serem removidas
                            cout << "Lista de músicas a serem removidas:" << endl;
                            lista_temp2.imprime();
                            cout << endl;

                            if(lista_temp.remove(lista_temp2)){ // Verifica se a remoção foi bem sucedida
                                cout << "Lista inicial após remoção: " << endl;
                                lista_temp.imprime();
                                cout << endl << "Músicas removidas com sucesso!" << endl;

                            }else{
                                cout << "Erro ao remover músicas!" << endl;
                            }

                            // Limpa as listsa temporárias
                            for(int i = lista_temp.getTamanho() - 1; i >= 0; i--){
                                lista_temp.remove(i);
                            }

                            for(int i = lista_temp2.getTamanho() - 1; i >= 0; i--){
                                lista_temp2.remove(i);
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 3:{ // Construtor cópia (1.C)

                            // Monta e insere as músicas na lista original
                            musica.setNome("Pra Animar o Bar");
                            musica.setArtista("Cícero");
                            lista_temp.insereFim(musica);

                            musica.setNome("What's Going On");
                            musica.setArtista("Marvin Gaye");
                            lista_temp.insereFim(musica);

                            musica.setNome("Heartbreak Anniversary");
                            musica.setArtista("Giveon");
                            lista_temp.insereFim(musica);

                            Lista lista_temp4(lista_temp); // Declara a lista temporária utilizando o construtor cópia
                            
                            // Imprime as listas informando seus endereços na memória
                            cout << "Lista original: (Endereço da lista: " << &lista_temp << ")" << endl;
                            for(int i = 0; i < lista_temp.getTamanho(); i++){
                                cout << i + 1 << ". " << lista_temp.buscaMusicaPos(i)->getNome() << " - " << lista_temp.buscaMusicaPos(i)->getArtista() << " (Endereço da música: " << lista_temp.buscaMusicaPos(i) << ")" << endl;
                            }

                            cout << endl << "Lista cópia: (Endereço da lista: " << &lista_temp4 << ")" << endl;
                            for(int i = 0; i < lista_temp4.getTamanho(); i++){
                                cout << i + 1 << ". " << lista_temp4.buscaMusicaPos(i)->getNome() << " - " << lista_temp4.buscaMusicaPos(i)->getArtista() << " (Endereço da música: " << lista_temp4.buscaMusicaPos(i) << ")" << endl;
                            }

                            // Limpa as listas temporárias
                            for(int i = lista_temp.getTamanho() - 1; i >= 0; i--){ 
                                lista_temp.remove(i);
                            }

                            for(int i = lista_temp4.getTamanho() - 1; i >= 0; i--){ 
                                lista_temp4.remove(i);
                            }

                            cout << endl;

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        }
                        case 4: // Operador "+" (2.A)
                            
                            // Insere as músicas na primeira lista temporária
                            musica.setNome("Pra Animar o Bar");
                            musica.setArtista("Cícero");
                            lista_temp.insereFim(musica);

                            musica.setNome("What's Going On");
                            musica.setArtista("Marvin Gaye");
                            lista_temp.insereFim(musica);

                            musica.setNome("Heartbreak Anniversary");
                            musica.setArtista("Giveon");
                            lista_temp.insereFim(musica);

                            // Monta e insere músicas na segunda lista temporária
                            musica.setNome("What's Going On");
                            musica.setArtista("Marvin Gaye");
                            lista_temp2.insereFim(musica);

                            musica.setNome("Runaway");
                            musica.setArtista("AURORA");
                            lista_temp2.insereFim(musica);

                            musica.setNome("Time Machine");
                            musica.setArtista("WILLOW");
                            lista_temp2.insereFim(musica);

                            // Atribui o retorno da concatenação a um novo objeto
                            lista_temp3 = lista_temp + lista_temp2;

                            // Imprime as listas ao usuário
                            cout << "Lista C = (Lista A + Lista B): " << endl;
                            lista_temp3->imprime();
                            cout << endl;

                            cout << "Lista A: " << endl;
                            lista_temp.imprime();
                            cout << endl;

                            cout << "Lista B:" << endl;
                            lista_temp2.imprime();
                            cout << endl;

                            // Limpa as listas temporárias
                            for(int i = lista_temp.getTamanho() - 1; i >= 0; i--){
                                lista_temp.remove(i);
                            }

                            for(int i = lista_temp2.getTamanho() - 1; i >= 0; i--){
                                lista_temp2.remove(i);
                            }

                            for(int i = lista_temp3->getTamanho() - 1; i >= 0; i--){
                                lista_temp3->remove(i);
                            }

                            delete lista_temp3;

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 5: // Operador de extração ">>" (2.B)
                            /* code */
                            break;

                        case 6: // Operador de inserção "<<" (2.C)
                            /* code */
                            break;

                        case 7: // Adicionar músicas (3.A)
                            
                            // Monta e insere músicas na playlist inicial
                            playlist_temp.setNome("Playlist inicial");

                            // Monta e insere músicas na playlist inicial
                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Devil's Whisper");
                            musica.setArtista("Raury");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Plastic 100ºC");
                            musica.setArtista("Sampha");
                            playlist_temp.insereFim(musica);

                            // Imprime a playlist incial
                            cout << "Playlist inicial: " << endl;
                            playlist_temp.imprime(playlist_temp.getLista()->buscaPos(0), 1);
                            cout << endl;

                            // Monta e insere as músicas na playlist de músicas a serem inseridas
                            playlist_temp2.setNome("Playlist a ser inserida");

                            musica.setNome("Call it Home");
                            musica.setArtista("Milla Sampaio");
                            playlist_temp2.insereFim(musica);

                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");
                            playlist_temp2.insereFim(musica);

                            musica.setNome("TAKE TIME");
                            musica.setArtista("Giveon");
                            playlist_temp2.insereFim(musica);

                            // Imprime a playlist de músicas a serem inseridas
                            cout << "Playlist de músicas a serem inseridas: " << endl;
                            playlist_temp2.imprime(playlist_temp2.getLista()->buscaPos(0), 1);
                            cout << endl;

                            if(playlist_temp.insereFim(playlist_temp2)){ // Verifica se a inserção foi bem sucedida
                                cout << endl << "Playlist inicial após inserção: " << endl;
                                playlist_temp.imprime(playlist_temp.getLista()->buscaPos(0), 1);
                                cout << endl << "Músicas inseridas com sucesso!" << endl;

                            }else{
                                cout << "\nErro ao inserir músicas à playlist!" << endl;
                            }

                            // Limpa as playlists temporárias
                            for(int i = playlist_temp.getLista()->getTamanho() - 1; i >= 0; i--){ // Limpa a playlist temporária
                                playlist_temp.remove(i);
                            }

                            for(int i = playlist_temp2.getLista()->getTamanho() - 1; i >= 0; i--){ // Limpa a playlist temporária
                                playlist_temp2.remove(i);
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 8: // Remover músicas (3.B)

                            // Monta e insere músicas na playlist inicial
                            playlist_temp.setNome("Playlist inicial");

                            // Monta e insere músicas na playlist inicial
                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Devil's Whisper");
                            musica.setArtista("Raury");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Plastic 100ºC");
                            musica.setArtista("Sampha");
                            playlist_temp.insereFim(musica);

                            // Imprime a playlist incial
                            cout << "Playlist inicial: " << endl;
                            playlist_temp.imprime(playlist_temp.getLista()->buscaPos(0), 1);
                            cout << endl;

                            // Monta e insere músicas na playlist de músicas a serem removidas
                            playlist_temp.setNome("Playlist de músicas a serem removidas");

                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");
                            playlist_temp2.insereFim(musica);

                            musica.setNome("Devil's Whisper");
                            musica.setArtista("Raury");
                            playlist_temp2.insereFim(musica);

                            musica.setNome("New Light");
                            musica.setArtista("John Mayer");
                            playlist_temp2.insereFim(musica);

                            // Imprime a playlist de músicas a serem removidas
                            cout << "Playlist de músicas a serem removidas:" << endl;
                            playlist_temp2.imprime(playlist_temp2.getLista()->buscaPos(0), 1);
                            cout << endl << endl;

                            cout << playlist_temp.remove(playlist_temp2) << " músicas foram removidas da playlist!" << endl;

                            // Limpa as playlists temporárias
                            for(int i = playlist_temp.getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp.remove(i);
                            }

                            for(int i = playlist_temp2.getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp2.remove(i);
                            }

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 9:{ // Construtor cópia (3.C)

                            // Monta e insere músicas na playlist inicial
                            playlist_temp.setNome("Playlist inicial");

                            // Monta e insere músicas na playlist inicial
                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Devil's Whisper");
                            musica.setArtista("Raury");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Plastic 100ºC");
                            musica.setArtista("Sampha");
                            playlist_temp.insereFim(musica);

                            Playlist playlist_temp4(playlist_temp); // Declara a playlist temporária utilizando o construtor cópia

                            // Imprime as playlists informando seus endereços na memória
                            cout << "Playlist original: (Endereço da lista: " << playlist_temp.getLista() << ")" << endl;
                            cout << "Nome da playlist original: " << playlist_temp.getNome() << endl;
                            for(int i = 0; i < playlist_temp.getLista()->getTamanho(); i++){
                                cout << i + 1 << ". " << playlist_temp.getLista()->buscaMusicaPos(i)->getNome() << " - " << playlist_temp.getLista()->buscaMusicaPos(i)->getArtista() << " (Endereço da música: " << playlist_temp.getLista()->buscaMusicaPos(i) << ")" << endl;
                            }

                            cout << endl << "Playlist cópia: (Endereço da lista: " << playlist_temp4.getLista() << ")" << endl;
                            cout << "Nome da playlist cópia: " << playlist_temp4.getNome() << endl;
                            for(int i = 0; i < playlist_temp4.getLista()->getTamanho(); i++){
                                cout << i + 1 << ". " << playlist_temp4.getLista()->buscaMusicaPos(i)->getNome() << " - " << playlist_temp4.getLista()->buscaMusicaPos(i)->getArtista() << " (Endereço da música: " << playlist_temp4.getLista()->buscaMusicaPos(i) << ")" << endl;
                            }

                            // Limpa as listas temporárias
                            for(int i = playlist_temp.getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp.remove(i);
                            }

                            for(int i = playlist_temp4.getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp4.remove(i);
                            }

                            cout << endl;

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        }
                        case 10: // Operador "+" versão 1 (4.A)

                            // Monta e insere músicas na playlist inicial
                            playlist_temp.setNome("Playlist A");

                            // Monta e insere músicas na playlist inicial
                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Devil's Whisper");
                            musica.setArtista("Raury");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Plastic 100ºC");
                            musica.setArtista("Sampha");
                            playlist_temp.insereFim(musica);

                            // Monta e insere as músicas na playlist de músicas a serem inseridas
                            playlist_temp2.setNome("Playlist B");

                            musica.setNome("Call it Home");
                            musica.setArtista("Milla Sampaio");
                            playlist_temp2.insereFim(musica);

                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");
                            playlist_temp2.insereFim(musica);

                            musica.setNome("TAKE TIME");
                            musica.setArtista("Giveon");
                            playlist_temp2.insereFim(musica);

                            // Atribui o retorno da união a um novo objeto
                            playlist_temp3 = playlist_temp + playlist_temp2;

                            // Imprime as playlists ao usuário
                            cout << "\nPlaylist C = (Playlist A U Playlist B): " << endl;
                            playlist_temp3->imprime(playlist_temp3->getLista()->buscaPos(0), 1);
                            cout << endl;
                            
                            cout << "Playlist A:" << endl;
                            playlist_temp.imprime(playlist_temp.getLista()->buscaPos(0), 1);
                            cout << endl;

                            cout << "Playlist B:" << endl;
                            playlist_temp2.imprime(playlist_temp2.getLista()->buscaPos(0), 1);
                            cout << endl;

                            // Limpa as playlists temporárias
                            for(int i = playlist_temp.getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp.remove(i);
                            }

                            for(int i = playlist_temp2.getLista()->getTamanho() - 1; i >= 0; i--) {
                                playlist_temp2.remove(i);
                            }

                            for(int i = playlist_temp3->getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp3->remove(i);
                            }

                            delete playlist_temp3;

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 11: // Operador "+" versão 2 (4.B)

                            // Monta e insere músicas na playlist inicial
                            playlist_temp.setNome("Playlist A");

                            // Monta e insere músicas na playlist inicial
                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Devil's Whisper");
                            musica.setArtista("Raury");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Plastic 100ºC");
                            musica.setArtista("Sampha");
                            playlist_temp.insereFim(musica);

                            // Define música a ser enviada no parâmetro da união
                            musica.setNome("Bohemian Rhapsody");
                            musica.setArtista("Queen");

                            // Atribui o retorno da união a um novo objeto
                            playlist_temp3 = playlist_temp + musica;

                            // Imprime as playlists ao usuário
                            cout << "\nPlaylist união = (Playlist original + Música): " << endl;
                            playlist_temp3->imprime(playlist_temp3->getLista()->buscaPos(0), 1);
                            cout << endl;
                            
                            cout << "Música: " << endl << musica.getNome() << " - " << musica.getArtista() << endl << endl;
                            
                            cout << "Playlist original:" << endl;
                            playlist_temp.imprime(playlist_temp.getLista()->buscaPos(0), 1);
                            cout << endl;

                            // Limpa as playlists temporárias
                            for(int i = playlist_temp.getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp.remove(i);
                            }

                            for(int i = playlist_temp3->getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp3->remove(i);
                            }

                            delete playlist_temp3;

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 12: // Operador "-" versão 1 (4.C)

                            // Monta e insere músicas na playlist inicial
                            playlist_temp.setNome("Playlist A");

                            // Monta e insere músicas na playlist inicial
                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Devil's Whisper");
                            musica.setArtista("Raury");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Plastic 100ºC");
                            musica.setArtista("Sampha");
                            playlist_temp.insereFim(musica);

                            // Monta e insere as músicas na playlist de músicas a serem inseridas
                            playlist_temp2.setNome("Playlist B");

                            musica.setNome("Plastic 100ºC");
                            musica.setArtista("Sampha");
                            playlist_temp2.insereFim(musica);

                            musica.setNome("The Less I Know The Better");
                            musica.setArtista("Tame Impala");
                            playlist_temp2.insereFim(musica);

                            musica.setNome("Seigfried");
                            musica.setArtista("Frank Ocean");
                            playlist_temp2.insereFim(musica);

                            // Atribui o retorno da diferença a um novo objeto
                            playlist_temp3 = playlist_temp - playlist_temp2;

                            // Imprime as playlists ao usuário
                            cout << "\nPlaylist C (Playlist A - Playlist B): " << endl;
                            playlist_temp3->imprime(playlist_temp3->getLista()->buscaPos(0), 1);
                            cout << endl;
                            
                            cout << "Playlist A:" << endl;
                            playlist_temp.imprime(playlist_temp.getLista()->buscaPos(0), 1);
                            cout << endl;

                            cout << "Playlist B:" << endl;
                            playlist_temp2.imprime(playlist_temp2.getLista()->buscaPos(0), 1);
                            cout << endl;

                            // Limpa as playlists temporárias
                            for(int i = playlist_temp.getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp.remove(i);
                            }

                            for(int i = playlist_temp2.getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp2.remove(i);
                            }

                            for(int i = playlist_temp3->getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp3->remove(i);
                            }

                            delete playlist_temp3;

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 13: // Operador "-" versão 2 (4.D)

                            // Monta e insere músicas na playlist inicial
                            playlist_temp.setNome("Playlist Original");

                            // Monta e insere músicas na playlist inicial
                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Devil's Whisper");
                            musica.setArtista("Raury");
                            playlist_temp.insereFim(musica);

                            musica.setNome("Plastic 100ºC");
                            musica.setArtista("Sampha");
                            playlist_temp.insereFim(musica);

                            // Define música a ser enviada no parâmetro da diferença
                            musica.setNome("IknowhowIfeel");
                            musica.setArtista("Parcels");

                            // Atribui o retorno da diferença a um novo objeto
                            playlist_temp3 = playlist_temp - musica;

                            // Imprime as playlists ao usuário
                            cout << "Playlist diferença = (Playlist original - Música): " << endl;
                            playlist_temp3->imprime(playlist_temp3->getLista()->buscaPos(0), 1);
                            cout << endl;

                            cout << "Música: " << endl << musica.getNome() << " - " << musica.getArtista() << endl << endl;
                            
                            cout << "Playlist original:" << endl;
                            playlist_temp.imprime(playlist_temp.getLista()->buscaPos(0), 1);
                            cout << endl;

                            // Limpa as playlists temporárias
                            for(int i = playlist_temp.getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp.remove(i);
                            }

                            for(int i = playlist_temp3->getLista()->getTamanho() - 1; i >= 0; i--){
                                playlist_temp3->remove(i);
                            }

                            delete playlist_temp3;

                            cout << "Pressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 14: // Operador de extração ">>" (4.E)
                            /* code */
                            break;

                        case 15: // Operador de inserção "<<" (4.F)
                            /* code */
                            break;

                        case 16:
                            break; // Sair

                        default:
                            break;
                    }

                    system("clear");

                }while(op2 != 16);

                break;

            case 4: break; // Sair

            default: // Opção inválida
                cout << "Opção inválida!" << endl;
                cout << "Pressione ENTER para continuar..." << endl;
                getchar();
                system("clear");
                break;
        }

    }while(op1 != 4);

    cout << "Programa encerrado!" << endl << endl;

    // Libera os espaços de memória alocados dinamicamente para as músicas do sistema e para as playlists
    delete musicas_sistema;
    delete[] playlists;

    return 0;
}