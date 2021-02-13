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
    int op1 = 0, op2 = 0, op3 = 0, qtd_pl = 0, posicao;
    string nome_musica, nome_artista, s_op, nome_playlist;
    Musica musica;
    Lista musicas_sistema;
    Playlist playlists[MAX_PL], aux_pl;

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
                                cin >> posicao;
                                cin.ignore();

                                if(posicao > musicas_sistema.getTamanho() + 1){ // Verifica se a posição é válida
                                    cout << "Posição inválida!" << endl;

                                }else{
                                    if(musicas_sistema.inserePos(posicao, musica)){ // Chama a função e verifica se a inserção foi bem sucedida
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

                            cout << "Pressione qualquer tecla para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 2: // Remover música

                            if(musicas_sistema.getTamanho() > 0){ // Verifica se há músicas cadastradas
                                
                                musicas_sistema.imprime(); // Imprime a lista de músicas para o usuário
                                
                                cout << "\nDigite o número da música que deseja remover do sistema:" << endl;
                                cin >> posicao;
                                cin.ignore();

                                if(posicao >= 1 && posicao <= musicas_sistema.getTamanho()){ // Verifica se a posição digitada é válida

                                /*
                                *
                                *       DELETAR DAS PLAYLISTS TAMBÉM
                                *
                                */

                                    musicas_sistema.removePos(posicao); // Remove a música do sistema
                                    
                                    cout << "\nMúsica removida com sucesso!" << endl;
                                }else{
                                    cout << "\nPosição inválida!" << endl;
                                }
                            }else{
                                cout << "Não há músicas cadastradas no sistema!" << endl;
                            }
                            
                            cout << "\nPressione qualquer tecla para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;

                        case 3: // Exibir músicas cadastradas

                            if(musicas_sistema.getTamanho() > 0){ // Verifica se há músicas cadastradas
                                musicas_sistema.imprime(); // Imprime a lista de músicas para o usuário
                            }else{
                                cout << "Não há músicas cadastradas no sistema!" << endl;
                            }

                            cout << "\nPressione qualquer tecla para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 4: break;

                        default: // Opção inválida
                            cout << "\nOpção inválida!" << endl;
                            cout << "\nPressione qualquer tecla para continuar..." << endl;
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
                                getline(cin, nome_playlist);

                                flag = 0;
                                for(int i = 0; i < qtd_pl; i++){ // Verifica se há uma playlist com o mesmo nome
                                    if(nome_playlist == playlists[i].getNome()){
                                        flag = true;
                                    }
                                }

                                if(!flag){
                                    // A playlist não existe e pode ser adicionada
                                    playlists[qtd_pl].setNome(nome_playlist);
                                    qtd_pl++;
                                    // VERIFICAR SE HÁ MAIS ALGO A FAZER AQUI
                                    cout << "\nPlaylist \"" << playlists[qtd_pl].getNome() << "\" adicionada com sucesso!" << endl;
                                }else{
                                    cout << "\nEsta playlist já existe!" << endl;
                                }

                            }else{
                                cout << "Você já atingiu o limite de playlists!" << endl;
                            }

                            cout << "\nPressione qualquer tecla para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 2: // Remover playlist

                            if(qtd_pl > 0){ // Verifica se há playlists cadastradas

                                for(int i = 0; i < qtd_pl; i++){ // Exibe as playlists cadastradas
                                    cout << i+1 << " - " << playlists[i].getNome() << endl;
                                }

                                cout << "\nDigite o número da playlist que deseja remover:" << endl;
                                cin >> posicao;
                                cin.ignore();

                                if(posicao >= 1 && posicao <= qtd_pl){ // Verifica se a posição é válida
                                    
                                    posicao--; // Ajusta a posição para a faixa de valores dos índices (0 -> n-1)
                                    for(int i = posicao; i < qtd_pl - 1; i++){ // Percorre o array realocando as posições
                                        playlists[i].setNome(playlists[i+1].getNome());
                                        playlists[i].setLista(playlists[i+1].getLista());
                                    }
                                    qtd_pl--; // Atualiza o tamanho da playlist

                                    cout << "Playlist removida com sucesso!" << endl;

                                }else{
                                    cout << "\nPosição inválida!" << endl;
                                }
                            }else{
                                cout << "Não há nenhuma playlist cadastrada!" << endl;
                            }

                            cout << "\nPressione qualquer tecla para continuar..." << endl;
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
                            
                            cout << "\nPressione qualquer tecla para continuar..." << endl;
                            getchar();
                            system("clear");

                            break;
                        
                        case 4: break;

                        default:
                            cout << "\nOpção inválida!" << endl;
                            cout << "\nPressione qualquer tecla para continuar..." << endl;
                            getchar();
                            system("clear");
                            break;

                    }

                }while (op2 != 4);

                break;

            case 3: // Menu de musicas das playlists

                if(qtd_pl > 0){ // Verifica se há playlists cadastradas
                
                    for(int i = 0; i < qtd_pl; i++){
                        cout << i+1 << " - " << playlists[i].getNome();
                    }

                    do{
                        cout << "Digite o número da playlist que deseja abrir:" << endl;
                        cin >> op3;
                        cin.ignore();
                        if(op3 < 1 || op3 > qtd_pl){
                            cout << "Playlist inválida! Escolha novamente!" << endl;
                        }
                    }while(op3 < 1 || op3 > qtd_pl);
                    
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
                                break;
                            
                            case 2: // Remover música
                                break;

                            case 3: // Mover música
                                break;
                            
                            case 4: // Exibir músicas da playlist
                                
                                if(playlists->getLista()->getTamanho() > 0){
                                    // CHAMAR FUNÇÃO RECURSIVA AQUI
                                }else{
                                    cout << "Não há nenhuma música nessa playlist!" << endl;
                                }

                                cout << "\nPressione qualquer tecla para continuar..." << endl;
                                getchar();
                                system("clear");

                                break;

                            case 5: break;
                            
                            default:
                                cout << "\nOpção inválida!" << endl;
                                cout << "\nPressione qualquer tecla para continuar..." << endl;
                                getchar();
                                system("clear");
                                break;

                        }

                    }while (op2 != 5);

                }else{
                    cout << "Nenhuma playlist cadastrada!\nAdicione uma playlist em \"Playlists\" no Menu Principal!" << endl;
                }

                cout << "\nPressione qualquer tecla para continuar..." << endl;
                getchar();
                system("clear");

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

                cout << "\nPressione qualquer tecla para continuar..." << endl;
                getchar();
                system("clear");

                break;

            case 5: break;

            default: // Opção inválida
                cout << "\nOpção inválida!" << endl;
                cout << "\nPressione qualquer tecla para continuar..." << endl;
                getchar();
                system("clear");
                break;
        }

    }while(op1 != 5);
    
    cout << "Programa encerrado!" << endl << endl;

    return 0;
}