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
    
    bool flag = false;
    int op1 = 0, op2 = 0, op3 = 0, op4 = 0, qtd_pl = 0, posicao1, posicao2;
    string nome_musica, nome_artista, s_op, nome_playlist;
    Musica musica;
    Lista musicas_sistema;
    Playlist *playlists = new Playlist[MAX_PL], aux_pl;
    //Playlist playlists[MAX_PL], aux_pl;

    //system("clear");

    // Apresentação do menu principal do programa
    do{
        cout << "------------ MENU PRINCIPAL ------------" << endl;
        cout << "1 - Músicas do sistema" << endl;
        cout << "2 - Playlists" << endl;
        cout << "3 - Músicas das playlists" << endl;
        cout << "4 - Tocar música" << endl;
        cout << "5 - Sair" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Digite a opção: ";
        getline(cin, s_op);
        std::stringstream op(s_op);
        op >> op1;
        cout << endl;
        system("clear");

        switch (op1){

            case 1: // Menu de musicas do sistema
                
                do{
                    
                    cout << "---------- MUSICAS DO SISTEMA ----------" << endl;
                    cout << "1 - Adicionar música" << endl;
                    cout << "2 - Remover música" << endl;
                    cout << "3 - Exibir músicas cadastradas" << endl;
                    cout << "4 - Voltar" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Digite a opção: ";
                    getline(cin, s_op);
                    std::stringstream op(s_op);
                    op >> op2;
                    cout << endl;
                    system("clear");

                    switch(op2){
                        case 1: // Adicionar música

                            cout << "Digite o nome da música:" << endl;
                            getline(cin, nome_musica);
                            cout << "Digite o nome do artista:" << endl;
                            getline(cin, nome_artista);

                            musica.setNome(nome_musica);
                            musica.setArtista(nome_artista);

                            cout << "Deseja incluir em alguma posição específica? Não(1) ou Sim(2)?" << endl;
                            cin >> op3;
                            cin.ignore();

                            if(op3 == 2){
                                cout << "Digite a posição:" << endl;
                                cin >> posicao1;
                                cin.ignore();

                                if(posicao1 > musicas_sistema.getTamanho() + 1){ // Verifica se a posição é válida
                                    cout << "Posição inválida!" << endl;

                                }else{
                                    if(musicas_sistema.inserePos(posicao1, musica)){ // Chama a função e verifica se a inserção foi bem sucedida
                                        cout << "\nMúsica cadastrada no sistema com sucesso!" << endl;
                                    }else{
                                        cout << "\nErro ao cadastrar música no sistema!" << endl;
                                    }

                                }

                            }else{
                                if(op3 == 1){
                                    if(musicas_sistema.insereFim(musica)){ // Verifica se a inserção foi bem sucedida
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

                            if(musicas_sistema.getTamanho() > 0){ // Verifica se há músicas cadastradas
                                
                                musicas_sistema.imprime(); // Imprime a lista de músicas para o usuário
                                
                                cout << "\nDigite o número da música que deseja remover do sistema:" << endl;
                                cin >> posicao1;
                                cin.ignore();

                                if(posicao1 >= 1 && posicao1 <= musicas_sistema.getTamanho()){ // Verifica se a posição digitada é válida

                                /*
                                *
                                *       DELETAR DAS PLAYLISTS TAMBÉM
                                *
                                */

                                    musicas_sistema.removePos(posicao1); // Remove a música do sistema
                                    
                                    cout << "\nMúsica removida com sucesso!" << endl;
                                }else{
                                    cout << "\nPosição inválida!" << endl;
                                }
                            }else{
                                cout << "Não há músicas cadastradas no sistema!" << endl;
                            }
                            
                            cout << "\nPressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 3: // Exibir músicas cadastradas

                            if(musicas_sistema.getTamanho() > 0){ // Verifica se há músicas cadastradas
                                musicas_sistema.imprime(); // Imprime a lista de músicas para o usuário
                            }else{
                                cout << "Não há músicas cadastradas no sistema!" << endl;
                            }

                            cout << "\nPressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 4: break;

                        default: // Opção inválida
                            cout << "\nOpção inválida!" << endl;
                            cout << "\nPressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");
                            break;
                    }

                }while (op2 != 4);

                break;

            case 2: // Menu de playlists
                                
                do{
                
                    cout << "-------------- PLAYLISTS ---------------" << endl;
                    cout << "1 - Adicionar playlist" << endl;
                    cout << "2 - Remover playlist" << endl;
                    cout << "3 - Exibir playlists" << endl;
                    cout << "4 - Voltar" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Digite a opção: ";
                    getline(cin, s_op);
                    std::stringstream op(s_op);
                    op >> op2;
                    cout << endl;
                    system("clear");

                    switch(op2){
                        case 1: // Adicionar playlist

                            if(qtd_pl <= MAX_PL){ // Verifica se o número máximo de playlists permitidas já foi atingido
                                cout << "Digite o nome da playlist que deseja inserir:" << endl;
                                fflush(stdin);
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
                                    cout << "\nPlaylist \"" << playlists[qtd_pl].getNome() << "\" adicionada com sucesso!" << endl;
                                    qtd_pl++;
                                    // VERIFICAR SE HÁ MAIS ALGO A FAZER AQUI
                                }else{
                                    cout << "\nEsta playlist já existe!" << endl;
                                }

                            }else{
                                cout << "Você já atingiu o limite de playlists!" << endl;
                            }

                            cout << "\nPressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 2: // Remover playlist

                            if(qtd_pl > 0){ // Verifica se há playlists cadastradas

                                for(int i = 0; i < qtd_pl; i++){ // Exibe as playlists cadastradas
                                    cout << i+1 << ". " << playlists[i].getNome() << endl;
                                }

                                cout << "\nDigite o número da playlist que deseja remover:" << endl;
                                cin >> posicao1;
                                cin.ignore();

                                if (posicao1 >= 1 && posicao1 <= qtd_pl){ // Verifica se a posição é válida

                                    posicao1--; // Ajusta a posição para a faixa de valores dos índices (0 -> n-1)
                                    for (int i = posicao1; i < qtd_pl - 1; i++){ // Percorre o array realocando as posições
                                        playlists[i].setNome(playlists[i + 1].getNome());
                                        playlists[i].setLista(playlists[i + 1].getLista());
                                    }

                                    playlists[qtd_pl - 1].setNome("");
                                    playlists[qtd_pl - 1].setLista(nullptr);

                                    qtd_pl--; // Atualiza o tamanho da playlist

                                    cout << "Playlist removida com sucesso!" << endl;
                                }else{
                                    cout << "\nPosição inválida!" << endl;
                                }
                            }else{
                                cout << "Não há nenhuma playlist cadastrada!" << endl;
                            }

                            //     if(posicao1 >= 1 && posicao1 <= qtd_pl){ // Verifica se a posição é válida
                                    
                            //         posicao1--; // Ajusta a posição para a faixa de valores dos índices (0 -> n-1)

                            //         for(int i = playlists[posicao1].getLista()->getTamanho(); i > 0 ; i--){ // Remove todas as músicas da playlista a ser apagada
                            //             playlists[posicao1].removeMusicaPos(i);
                            //         }

                            //         delete playlists[posicao1].getLista();

                            //         playlists[posicao1].setLista(nullptr);

                            //         for(int i = posicao1; i < qtd_pl - 1; i++){ // Percorre o array de playlists realocando as posições
                            //             playlists[i].setNome(playlists[i+1].getNome());
                            //             playlists[i].setLista(playlists[i+1].getLista());
                            //         }

                            //         //delete playlists[qtd_pl - 1].getLista();
                            //         qtd_pl--; // Atualiza o tamanho da playlist

                            //         cout << "Playlist removida com sucesso!" << endl;

                            //     }else{
                            //         cout << "\nPosição inválida!" << endl;
                            //     }
                            // }else{
                            //     cout << "Não há nenhuma playlist cadastrada!" << endl;
                            // }

                            cout << "\nPressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 3: // Exibe as playlists cadastradas

                            if(qtd_pl > 0){
                                for(int i = 0; i < qtd_pl; i++){
                                    cout << i+1 << ". " << playlists[i].getNome() << endl;
                                }
                            }else{
                                cout << "Não há nenhuma playlist cadastrada!" << endl;
                            }
                            
                            cout << "\nPressione ENTER para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 4: break;

                        default:
                            cout << "\nOpção inválida!" << endl;
                            break;

                    }

                }while (op2 != 4);

                break;

            case 3: // Menu de musicas das playlists

                if(qtd_pl > 0){ // Verifica se há playlists cadastradas
                
                    for(int i = 0; i < qtd_pl; i++){
                        cout << i+1 << " - " << playlists[i].getNome() << endl;
                    }

                    do{
                        cout << "\nDigite o número da playlist que deseja abrir:" << endl;
                        cin >> op3;
                        cin.ignore();
                        if(op3 < 1 || op3 > qtd_pl){
                            cout << "Playlist inválida! Escolha novamente!" << endl;
                        }
                    }while(op3 < 1 || op3 > qtd_pl);

                    op3--; // Adequa variável ao faixa de números de índices (0 - n-1)

                    system("clear");

                    do{
                                        
                        cout << "--------- MÚSICAS DA PLAYLIST ---------" << endl;
                        cout << "1 - Adicionar música" << endl;
                        cout << "2 - Remover música" << endl;
                        cout << "3 - Mover música" << endl;
                        cout << "4 - Exibir músicas da playlist" << endl;
                        cout << "5 - Voltar" << endl;
                        cout << "----------------------------------------" << endl;
                        cout << "Digite a opção: ";
                        getline(cin, s_op);
                        std::stringstream op(s_op);
                        op >> op2;
                        cout << endl;
                        system("clear");

                        switch(op2){
                            case 1: // Adicionar música

                                if(musicas_sistema.getTamanho() > 0){ // Verfica se há músicas no sistema

                                    // Imprime as músicas do sistema
                                    musicas_sistema.imprime();

                                    cout << "\n\nDigite a posição da música que deseja adicionar em \"" << playlists[op3].getNome() << "\":" << endl;
                                    cin >> posicao1;
                                    cin.ignore();

                                    musica = *musicas_sistema.buscaMusicaPos(posicao1 - 1);

                                    if(posicao1 > 0 && posicao1 <= musicas_sistema.getTamanho()){ // Verifica se a posição é válida
                                        if(playlists[op3].getLista()->buscaMusica(musica) == nullptr){ // Verifica se a música já existe na playlist

                                            cout << "\nDeseja adicionar esta música em uma posição específica de \"" << playlists[op3].getNome() << "\"? Não(1) ou Sim(2)" << endl;
                                            cin >> op4;
                                            cin.ignore();

                                            if(op4 == 1){
                                                // Insere no final
                                                if(playlists[op3].adicionaMusicaFim(musica)){ // Verifica se a inserção foi bem sucedida
                                                    cout << "\nMúsica adicionada na playlist com sucesso!" << endl;
                                                }else{
                                                    cout << "\nErro ao adicionar música na playlist!" << endl;
                                                }

                                            }else{
                                                // Insere em uma posição específica
                                                system("clear");
                                                // IMPRIME AS MUSICAS DA PLAYLIST
                                                playlists[op3].getLista()->imprime();

                                                cout << "\nDigite a posição em que deseja inserir a música: " << endl;
                                                cin >> posicao2;
                                                cin.ignore();

                                                if(posicao2 > 0 && posicao2 <= playlists[op3].getLista()->getTamanho()){ // Verifica se a posição é válida
                                                    if(playlists[op3].adicionaMusicaPos(posicao2, musica)){ // Verifica se a inserção foi bem sucedida
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
                                    cout << "\nNão há músicas cadastradas no sistema!" << endl;
                                }

                                cout << "\nPressione ENTER para continuar..." << endl;
                                getchar();
                                system("clear");

                                break;
                            
                            case 2: // Remover música
                                
                                if(playlists[op3].getLista()->getTamanho() > 0){ // Verifica se há músicas cadastradas
                                    
                                    playlists[op3].getLista()->imprime(); // Imprime a lista de músicas da playlist para o usuário
                                    
                                    cout << "\nDigite o número da música que deseja remover da playlist:" << endl;
                                    cin >> posicao1;
                                    cin.ignore();

                                    if(posicao1 >= 1 && posicao1 <= playlists[op3].getLista()->getTamanho()){ // Verifica se a posição digitada é válida

                                        playlists[op3].removeMusicaPos(posicao1);
                                        //musicas_sistema.removePos(posicao1); // Remove a música do sistema
                                        
                                        cout << "\nMúsica removida com sucesso!" << endl;
                                    }else{
                                        cout << "\nPosição inválida!" << endl;
                                    }
                                }else{
                                    cout << "Não há músicas para remover!" << endl;
                                }

                                cout << "\nPressione ENTER para continuar..." << endl;
                                getchar();
                                system("clear");

                                break;

                            case 3: // Mover música
                                break;
                            
                            case 4: // Exibir músicas da playlist
                                
                                if(playlists[op3].getLista()->getTamanho() > 0){
                                    // CHAMAR FUNÇÃO RECURSIVA AQUI
                                    playlists[op3].getLista()->imprime();
                                }else{
                                    cout << "Não há nenhuma música nessa playlist!" << endl;
                                }

                                cout << "\nPressione ENTER para continuar..." << endl;
                                getchar();
                                system("clear");

                                break;

                            case 5: break;
                            
                            default:
                                cout << "\nOpção inválida!" << endl;
                                cout << "\nPressione ENTER para continuar..." << endl;
                                getchar();
                                system("clear");
                                break;
                        }

                    }while (op2 != 5);

                }else{
                    cout << "Nenhuma playlist cadastrada!\nAdicione uma playlist em \"Playlists\" no Menu Principal!" << endl;
                    cout << "\nPressione ENTER para continuar..." << endl;
                    getchar();
                    system("clear");
                }

                break;

            case 4: // Tocar música
            
                if(qtd_pl > 0){ // Verifica se há playlists cadastradas
                
                    for(int i = 0; i < qtd_pl; i++){
                        cout << i+1 << " - " << playlists[i].getNome();
                    }

                    do{
                        cout << "Digite o número da playlist que deseja reproduzir:" << endl;
                        cin >> op3;
                        cin.ignore();
                        if(op3 < 1 || op3 > qtd_pl){
                            cout << "Playlist inválida! Escolha novamente!" << endl;
                        }
                    }while(op3 < 1 || op3 > qtd_pl);

                    //CONTINUAR CÓDIGO

                }else{
                    cout << "Nenhuma playlist cadastrada!\nAdicione uma playlist em \"Playlists\" no Menu Principal!" << endl;
                }

                cout << "\nPressione ENTER para continuar..." << endl;
                getchar();
                system("clear");

                break;

            case 5: break;

            default: // Opção inválida
                cout << "\nOpção inválida!" << endl;
                cout << "\nPressione ENTER para continuar..." << endl;
                getchar();
                system("clear");
                break;
        }

    }while(op1 != 5);

    cout << "Programa encerrado!" << endl << endl;

    delete[] playlists;

    return 0;
}