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
    Musica musica, *prox_musica;
    Lista *musicas_sistema = new Lista;
    Playlist *playlists = new Playlist[MAX_PL], aux_pl;

    system("clear");

    // Apresentação do menu principal do programa
    do{

        cout << "+---------------------------+" << endl;
        cout << "|      MENU PRINCIPAL       |" << endl;
        cout << "+---------------------------+" << endl;
        cout << "| 1 - Músicas do sistema    |" << endl;
        cout << "| 2 - Playlists             |" << endl;
        cout << "| 3 - Músicas das playlists |" << endl;
        cout << "| 4 - Tocar música          |" << endl;
        cout << "| 5 - Sair                  |" << endl;
        cout << "+---------------------------+" << endl;

        cout << "Digite uma opção: ";
        getline(cin, s_op);
        std::stringstream op(s_op);
        op >> op1;
        cout << endl;
        system("clear");

        switch (op1){

            case 1: // Menu de musicas do sistema
                
                do{

                    cout << "+--------------------------------+ " << endl;
                    cout << "|       MUSICAS DO SISTEMA       |" << endl;
                    cout << "+--------------------------------+" << endl;
                    cout << "| 1 - Adicionar música           |" << endl;
                    cout << "| 2 - Remover música             |" << endl;
                    cout << "| 3 - Exibir músicas cadastradas |" << endl;
                    cout << "| 4 - Voltar                     |" << endl;
                    cout << "+--------------------------------+" << endl;

                    cout << "Digite uma opção: ";
                    getline(cin, s_op);
                    std::stringstream op(s_op);
                    op >> op2;
                    cout << endl;
                    system("clear");

                    switch(op2){
                        case 1: // Adicionar música

                            cout << "Digite o nome da música:" << endl;
                            getline(cin, nome_musica);
                            cout << "\nDigite o nome do artista:" << endl;
                            getline(cin, nome_artista);

                            musica.setNome(nome_musica);
                            musica.setArtista(nome_artista);

                            cout << "\nDeseja incluir em alguma posição específica? Não(1) ou Sim(2)?" << endl;
                            cin >> op3;
                            cin.ignore();

                            if(op3 == 2){

                                system("clear");

                                musicas_sistema->imprime(); // Imprime a lista de músicas do sistema

                                cout << "\nDigite a posição:" << endl;
                                cin >> posicao1;
                                cin.ignore();

                                if(posicao1 > musicas_sistema->getTamanho() + 1){ // Verifica se a posição é válida
                                    cout << "\nPosição inválida!" << endl;

                                }else{
                                    if(musicas_sistema->inserePos(posicao1, musica)){ // Chama a função e verifica se a inserção foi bem sucedida
                                        cout << "\nMúsica cadastrada no sistema com sucesso!" << endl;

                                    }else{
                                        cout << "\nErro ao cadastrar música no sistema!" << endl;
                                    }
                                }

                            }else{
                                if(op3 == 1){
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
                                
                                cout << "\nDigite o número da música que deseja remover do sistema:" << endl;
                                cin >> posicao1;
                                cin.ignore();

                                if(posicao1 >= 1 && posicao1 <= musicas_sistema->getTamanho()){ // Verifica se a posição digitada é válida

                                    musica = *(musicas_sistema->buscaMusicaPos(posicao1 - 1)); // Recebe a música da posição especificada

                                    for(int i = 0; i < qtd_pl; i++){ // Laço para percorrer o array de playlists procurando por playlists com a música a ser apagada
                                        if(playlists[i].getLista()->buscaMusica(musica) != nullptr){
                                            for(int j = 0; j < playlists[i].getLista()->getTamanho(); j++){ // Percorre os elementos da playlist para achar a posição da música a ser apagada
                                                if(playlists[i].getLista()->buscaMusicaPos(j)->getNome() == musica.getNome() && playlists[i].getLista()->buscaMusicaPos(j)->getArtista() == musica.getArtista()){
                                                    cout << "\nA música " << playlists[i].getLista()->buscaMusicaPos(j)->getNome() << " de " << playlists[i].getLista()->buscaMusicaPos(j)->getArtista() << " estava na posição " << j+1 <<  " da playlist " << playlists[i].getNome() << " e foi removida!";
                                                    playlists[i].removeMusicaPos(j + 1); // Apaga a música da playlist
                                                }
                                            }
                                        }
                                    }

                                    musicas_sistema->removePos(posicao1); // Remove a música do sistema
                                    
                                    cout << "\nMúsica removida do sistema com sucesso!" << endl;

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
                        
                        case 4: break;

                        default: // Opção inválida
                            cout << "\nOpção inválida!" << endl;
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
                    cout << "| 4 - Voltar             |" << endl;
                    cout << "+------------------------+" << endl;

                    cout << "Digite uma opção: ";
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

                                cout << "\nDigite o número da playlist que deseja remover:" << endl;
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
                        
                        case 4: break;

                        default:
                            cout << "\nOpção inválida!" << endl;
                            break;
                    }

                }while (op2 != 4);

                break;

            case 3: // Menu de musicas das playlists

                if(qtd_pl > 0){ // Verifica se há playlists cadastradas
                
                    for(int i = 0; i < qtd_pl; i++){ // Imprime o nome das playlists
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

                        cout << "+--------------------------------+" << endl;
                        cout << "|     MÚSICAS DAS PLAYLISTS      |" << endl;
                        cout << "+--------------------------------+" << endl;
                        cout << "| 1 - Adicionar música           |" << endl;
                        cout << "| 2 - Remover música             |" << endl;
                        cout << "| 3 - Mover música               |" << endl;
                        cout << "| 4 - Exibir músicas da playlist |" << endl;
                        cout << "| 5 - Voltar                     |" << endl;
                        cout << "+--------------------------------+" << endl;

                        cout << "Digite uma opção: ";
                        getline(cin, s_op);
                        std::stringstream op(s_op);
                        op >> op2;
                        cout << endl;
                        system("clear");

                        switch(op2){
                            case 1: // Adicionar música

                                if(musicas_sistema->getTamanho() > 0){ // Verfica se há músicas no sistema

                                    // Imprime as músicas do sistema
                                    musicas_sistema->imprime();

                                    cout << "\n\nDigite a posição da música que deseja adicionar em " << playlists[op3].getNome() << ":" << endl;
                                    cin >> posicao1;
                                    cin.ignore();

                                    if(posicao1 > 0 && posicao1 <= musicas_sistema->getTamanho()){ // Verifica se a posição é válida

                                        musica = *musicas_sistema->buscaMusicaPos(posicao1 - 1);

                                        if(playlists[op3].getLista()->buscaMusica(musica) == nullptr){ // Verifica se a música já existe na playlist

                                            cout << "\nDeseja adicionar esta música em uma posição específica de " << playlists[op3].getNome() << "? Não(1) ou Sim(2)" << endl;
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
                                                
                                                playlists[op3].imprime(playlists[op3].getLista()->buscaPos(0), 1); // Imprime as músicas da playlist

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
                                    cout << "Não há músicas cadastradas no sistema!" << endl << endl;
                                }

                                cout << "Pressione ENTER para continuar..." << endl;
                                getchar();
                                system("clear");

                                break;
                            
                            case 2: // Remover música
                                
                                if(playlists[op3].getLista()->getTamanho() > 0){ // Verifica se há músicas cadastradas

                                    playlists[op3].imprime(playlists[op3].getLista()->buscaPos(0), 1); // Imprime a lista de músicas da playlist para o usuário
                                    
                                    cout << "\nDigite o número da música que deseja remover da playlist:" << endl;
                                    cin >> posicao1;
                                    cin.ignore();

                                    if(posicao1 >= 1 && posicao1 <= playlists[op3].getLista()->getTamanho()){ // Verifica se a posição digitada é válida
                                        playlists[op3].removeMusicaPos(posicao1); // Remove música da playlist
                                        cout << "\nMúsica removida com sucesso!" << endl;

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

                                if(playlists[op3].getLista()->getTamanho() > 0){ // Verifica se há música na playlist

                                    if(playlists[op3].getLista()->getTamanho() > 1){ // Verifica se é possível mover músicas de lugar

                                        playlists[op3].imprime(playlists[op3].getLista()->buscaPos(0), 1);
                                        cout << endl;

                                        cout << "Digite a posição atual da música que deseja mover:" << endl;
                                        cin >> posicao1;
                                        cin.ignore();

                                        if(posicao1 > 0 && posicao1 <= playlists[op3].getLista()->getTamanho()){ // Verifica se a posição é válida
                                            cout << "Digite a posição para qual deseja mover:" << endl;
                                            cin >> posicao2;
                                            cin.ignore();

                                            if(posicao2 > 0 && posicao2 <= playlists[op3].getLista()->getTamanho()){ // Verifica se a posição é válida

                                                playlists[op3].moveMusica(posicao1, posicao2); // Move a música de lugar

                                                cout << "\nMúsica movida com sucesso!" << endl << endl;

                                                playlists[op3].imprime(playlists[op3].getLista()->buscaPos(0), 1); // Imprime nova organização das músicas
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

                                if(playlists[op3].getLista()->getTamanho() > 0){ // Verifica se há músicas na playlist
                                    playlists[op3].imprime(playlists[op3].getLista()->buscaPos(0), 1); // Imprime as músicas da playlist
                                    cout << endl;

                                }else{
                                    cout << "Não há nenhuma música nessa playlist!" << endl << endl;
                                }

                                cout << "Pressione ENTER para continuar..." << endl;
                                getchar();
                                system("clear");

                                break;

                            case 5: break;
                            
                            default:
                                cout << "\nOpção inválida!" << endl;
                                cout << "Pressione ENTER para continuar..." << endl;
                                getchar();
                                system("clear");
                                break;
                        }

                    }while (op2 != 5);

                }else{
                    cout << "Nenhuma playlist cadastrada!\nAdicione uma playlist em \"Playlists\" no Menu Principal!" << endl << endl;
                    cout << "Pressione ENTER para continuar..." << endl;
                    getchar();
                    system("clear");
                }

                break;

            case 4: // Tocar música
            
                if(qtd_pl > 0){ // Verifica se há playlists cadastradas
                
                    for(int i = 0; i < qtd_pl; i++){ // Imprime o nome das playlists
                        cout << i+1 << " - " << playlists[i].getNome() << endl;
                    }

                    do{
                        cout << "\nDigite o número da playlist que deseja reproduzir:" << endl;
                        cin >> op3;
                        cin.ignore();
                        if(op3 < 1 || op3 > qtd_pl){
                            cout << "\nPlaylist inválida! Escolha novamente!";
                        }
                    }while(op3 < 1 || op3 > qtd_pl); // Espera o usuário digitar uma posição válida

                    op3--; // Adequa variável ao faixa de números de índices (0 - n-1)

                    if(playlists[op3].getLista()->getTamanho() > 0){ // Verifica se a playlist tem músicas cadastradas

                        system("clear");

                        prox_musica = playlists[op3].proxMusica(); // Chama a função e recebe o ponteiro de música

                        if(prox_musica != nullptr){ // Verifica se a reprodução das músicas já chegou ao fim
                            cout << "Tocando " << prox_musica->getNome() << " - " << prox_musica->getArtista() << " da playlist " << playlists[op3].getNome() << "!" << endl << endl;

                        }else{
                            cout << "Você terminou de escutar essa playlist!" << endl << endl;
                        }

                    }else{
                        cout << "\nNão há nenhuma música nessa playlist para tocar!" << endl;
                    }

                }else{
                    cout << "Nenhuma playlist cadastrada!\nAdicione uma playlist em \"Playlists\" no Menu Principal!" << endl << endl;
                }

                cout << "Pressione ENTER para continuar..." << endl;
                getchar();
                system("clear");

                break;

            case 5: break;

            default: // Opção inválida
                cout << "\nOpção inválida!" << endl;
                cout << "Pressione ENTER para continuar..." << endl;
                getchar();
                system("clear");
                break;
        }

    }while(op1 != 5);

    cout << "Programa encerrado!" << endl << endl;

    delete musicas_sistema;
    delete[] playlists;

    return 0;
}