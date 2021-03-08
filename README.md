# **YourJam**

Bem vindo ao _YourJam_, um sistema de gerenciamento de músicas e playlists implementado em C++!

# Instalando e executando

Com o terminal aberto no diretório em que deseja baixar o projeto, digite:

    $ git clone https://github.com/diegofilbal/YourJam.git

Entre no diretório do projeto com:

    $ cd YourJam

E para compilar e executar o programa, digite:

    $ make run

# Como usar o sistema

## Músicas do sistema

Para entrar no menu de músicas do sistema, digite **1** no Menu principal:

    +-----------------------------+
    |        MENU PRINCIPAL       |
    +-----------------------------+
    | 1 - Músicas do sistema      |
    | 2 - Playlists               |
    | 3 - Funções sobrecarregadas |
    |                             |
    +-----------------------------+
    | 4 - Sair                    |
    +-----------------------------+
    Digite uma opção: 1

O seguinte menu aparecerá na tela:

    +--------------------------------+
    |       MÚSICAS DO SISTEMA       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Exibir músicas cadastradas |
    |                                |
    +--------------------------------+
    | 4 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 

### Adicionar uma música ao sistema

Para adicionar uma música no sistema, escolha a opção **1** no menu de músicas do sistema.

    +--------------------------------+
    |       MÚSICAS DO SISTEMA       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Exibir músicas cadastradas |
    |                                |
    +--------------------------------+
    | 4 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 1

Logo em seguida, digite o nome e o artista da música da música e informe se deseja inserir a música em alguma posição expecífica da lista:

    Digite o nome da música: Blinding Lights

    Digite o nome do artista: The Weeknd

    Deseja incluir em alguma posição específica? Não(1) ou Sim(2)? 1

    Música cadastrada no sistema com sucesso!
    Pressione ENTER para continuar...

Se desejar inserir a música em uma posição específica da lista, basta escolher a opção **2** depois de digitar o nome e artista da música:

    Digite o nome da música: Golden

    Digite o nome do artista: Harry Styles

    Deseja incluir em alguma posição específica? Não(1) ou Sim(2): 2

Logo em seguida, aparecerá uma tela com as playlists cadastradas. Insira a posição em que deseja inserir a música:

    1. Blinding Lights - The Weeknd

    Digite a posição: 1

    Música cadastrada no sistema com sucesso!
    Pressione ENTER para continuar...

### Remover uma música do sistema

Para remover uma música, escolha a opção **2** no menu de músicas do sistema:

    +--------------------------------+
    |       MÚSICAS DO SISTEMA       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Exibir músicas cadastradas |
    |                                |
    +--------------------------------+
    | 4 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 2

Uma lista enumerada das músicas cadastradas no sistema aparecerá e você deve digitar o número da música que deseja remover do sistema:

    1. Golden - Harry Styles
    2. Blinding Lights - The Weeknd
    3. Like I Want You - Giveon
    4. After Hours - The Weeknd

    Digite o número da música que deseja remover do sistema: 1

    Música removida do sistema com sucesso!
    Pressione ENTER para continuar...

### Listar músicas do sistema

Para ver todas as músicas cadastradas, digite **3** no menu de músicas do sistema:

    +--------------------------------+
    |       MÚSICAS DO SISTEMA       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Exibir músicas cadastradas |
    |                                |
    +--------------------------------+
    | 4 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 3

A lista de músicas cadastradas aparecerá de forma enumerada na tela da seguinte forma:

    1. Blinding Lights - The Weeknd
    2. Like I Want You - Giveon
    3. After Hours - The Weeknd

    Pressione ENTER para continuar...

## Playlists

Para entrar no menu de playlists, digite **2** no Menu principal:

    +-----------------------------+
    |        MENU PRINCIPAL       |
    +-----------------------------+
    | 1 - Músicas do sistema      |
    | 2 - Playlists               |
    | 3 - Funções sobrecarregadas |
    |                             |
    +-----------------------------+
    | 4 - Sair                    |
    +-----------------------------+
    Digite uma opção: 

O seguinte menu aparecerá na tela:

    +------------------------+
    |       PLAYLISTS        |
    +------------------------+
    | 1 - Adicionar playlist |
    | 2 - Remover playlist   |
    | 3 - Exibir playlists   |
    | 4 - Abrir uma playlist |
    |                        |
    +------------------------+
    | 5 - Voltar             |
    +------------------------+
    Digite uma opção: 

### Adicionar playlist

Para adicionar uma playlist, escolha a opção **1** no menu de playlists.

    +------------------------+
    |       PLAYLISTS        |
    +------------------------+
    | 1 - Adicionar playlist |
    | 2 - Remover playlist   |
    | 3 - Exibir playlists   |
    | 4 - Abrir uma playlist |
    |                        |
    +------------------------+
    | 5 - Voltar             |
    +------------------------+
    Digite uma opção: 1

Logo em seguida, digite o nome que deseja dar à playlist:

    Digite o nome da playlist que deseja inserir: Musicas Favoritas

    Playlist Musicas Favoritas adicionada com sucesso!
    Pressione ENTER para continuar...

### Remover playlist

Para remover uma playlist, escolha a opção **2** no menu de playlists:

    +------------------------+
    |       PLAYLISTS        |
    +------------------------+
    | 1 - Adicionar playlist |
    | 2 - Remover playlist   |
    | 3 - Exibir playlists   |
    | 4 - Abrir uma playlist |
    |                        |
    +------------------------+
    | 5 - Voltar             |
    +------------------------+
    Digite uma opção: 2

Uma lista enumerada das playlists cadastradas no sistema aparecererá e você deve digitar o número da playlist que deseja apagar:

    1. Musicas Favoritas
    2. Workout
    3. Para dormir

    Digite o número da playlist que deseja remover: 2

    Playlist removida com sucesso!
    Pressione ENTER para continuar...

### Listar playlists

Para ver todas as playlists cadastradas, digite **3** no menu de playlists:

    +------------------------+
    |       PLAYLISTS        |
    +------------------------+
    | 1 - Adicionar playlist |
    | 2 - Remover playlist   |
    | 3 - Exibir playlists   |
    | 4 - Abrir uma playlist |
    |                        |
    +------------------------+
    | 5 - Voltar             |
    +------------------------+
    Digite uma opção: 3

A lista de playlists cadastradas aparecerá de forma enumerada na tela da seguinte forma:

    1. Musicas Favoritas
    2. Para dormir

    Pressione ENTER para continuar...

### Abrir uma playlist

Para abrir uma playlist cadastrada e manipulá-la, digite **4** no menu de playlists:

    +------------------------+
    |       PLAYLISTS        |
    +------------------------+
    | 1 - Adicionar playlist |
    | 2 - Remover playlist   |
    | 3 - Exibir playlists   |
    | 4 - Abrir uma playlist |
    |                        |
    +------------------------+
    | 5 - Voltar             |
    +------------------------+
    Digite uma opção: 4

Logo em seguida, escolha a playlist que deseja abrir:

    1 - Musicas Favoritas
    2 - Para dormir

    Digite o número da playlist que deseja abrir: 1

O seguinte menu será exibido na tela:

    +--------------------------------+
    |      MÚSICAS DA PLAYLIST       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Mover música               |
    | 4 - Exibir músicas da playlist |
    | 5 - Reproduzir playlist        |
    |                                |
    +--------------------------------+
    | 6 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 

#### Adicionar uma música à playlist

Para adicionar uma música à playlist, escolha a opção **1** no menu de músicas da playlist:

    +--------------------------------+
    |      MÚSICAS DA PLAYLIST       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Mover música               |
    | 4 - Exibir músicas da playlist |
    | 5 - Reproduzir playlist        |
    |                                |
    +--------------------------------+
    | 6 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 1

Em seguida, uma lista enumerada das músicas do sistema aparecerá na tela e você deve digitar a posição da música que deseja adicionar à playlist, bem como informar se deseja adicioná-la em uma posição específica da playlist:

    1. Blinding Lights - The Weeknd
    2. Like I Want You - Giveon
    3. After Hours - The Weeknd

    Digite a posição da música que deseja adicionar em Musicas Favoritas: 2

    Deseja adicionar esta música em uma posição específica de Musicas Favoritas? Não(1) ou Sim(2): 1

Se desejar adicionar a música em uma posição específica da playlist, basta escolher a opção 2 depois de digitar o número da música:

    1. Blinding Lights - The Weeknd
    2. Like I Want You - Giveon
    3. After Hours - The Weeknd

    Digite a posição da música que deseja adicionar em Musicas Favoritas: 3

    Deseja adicionar esta música em uma posição específica de Musicas Favoritas? Não(1) ou Sim(2): 1

Uma lista das músicas da playlist aparecerá de forma enumerada na tela, em seguida digite a posição em eu deseja adicionar a música:

    1. Like I Want You - Giveon

    Digite a posição em que deseja inserir a música: 1

    Música adicionada na playlist com sucesso!
    Pressione ENTER para continuar...

#### Remover uma música da playlist

Para remover uma música da playlist, escolha a opção **2** do menu de músicas da playlist:

    +--------------------------------+
    |      MÚSICAS DA PLAYLIST       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Mover música               |
    | 4 - Exibir músicas da playlist |
    | 5 - Reproduzir playlist        |
    |                                |
    +--------------------------------+
    | 6 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 2

Em seguida, uma lista das músicas dessa playlist aparecerá de forma enumerada e você deve digitar o número da música que deseja remover da playlist:

    1. After Hours - The Weeknd
    2. Like I Want You - Giveon

    Digite o número da música que deseja remover da playlist: 2

    Música removida com sucesso!
    Pressione ENTER para continuar...

#### Mover uma música na playlist

Para mover uma música dentro de uma playlist, ou seja, posicioná-la em uma posição diferente da atual, escolha a opção **3** do menu de músicas da playlist:

    +--------------------------------+
    |      MÚSICAS DA PLAYLIST       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Mover música               |
    | 4 - Exibir músicas da playlist |
    | 5 - Reproduzir playlist        |
    |                                |
    +--------------------------------+
    | 6 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 3

Uma lista das músicas dessa playlist aparecerá de forma enumerada na tela e você deve informar o número da música que deseja mover e a posição para qual deseja que ela seja movida, repectivavamente:

    1. After Hours - The Weeknd
    2. Like I Want You - Giveon

    Digite a posição atual da música que deseja mover: 2
    Digite a posição para qual deseja mover: 1

Em seguida, será exibido na tela a nova ordem das músicas na tela:

    Música movida com sucesso!

    1. Like I Want You - Giveon
    2. After Hours - The Weeknd

    Pressione ENTER para continuar...

> Note que esta função não troca duas músicas de posição, o que ocorre é um deslocamento da música dentro da playlist. Como consequência, todas as músicas que estavam à frente dela terão suas posições atualizadas.

#### Exibir músicas da playlist

Para exibir todas as músicas dessa playlist, escolha a opção **4** do menu de músicas da playlist:

    +--------------------------------+
    |      MÚSICAS DA PLAYLIST       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Mover música               |
    | 4 - Exibir músicas da playlist |
    | 5 - Reproduzir playlist        |
    |                                |
    +--------------------------------+
    | 6 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 4

Logo em seguida, a lista de músicas da playlist aparecerá na tela:

    1. Like I Want You - Giveon
    2. After Hours - The Weeknd

    Pressione ENTER para continuar...

#### Reproduzir música da playlist

Para começar ou continuar a reprodução de uma playlist, escolha a opção **5** do menu de músicas da playlist:

    +--------------------------------+
    |      MÚSICAS DA PLAYLIST       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Mover música               |
    | 4 - Exibir músicas da playlist |
    | 5 - Reproduzir playlist        |
    |                                |
    +--------------------------------+
    | 6 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 5

Em seguida, a música que está sendo reproduzida no momento é informada na tela:

    Tocando Like I Want You - Giveon da playlist Musicas Favoritas!

Na primeira vez que essa opção for escolhida, a música reproduzida é a primeira da playlist. A partir daí, cada vez que a opção for escolhida novamente, a música a ser tocada é a próxima da playlist. É possível tocar músicas de uma playlist até que a última música seja reproduzida.

## Funções sobrecarregadas

As aplicações de todos os métodos sobrecarregados implementados podem ser consultadas a partir deste menu. Ele está disposto separadamente do restante das opções para facilitar o teste e análise de corretude dos algoritmos implementados. Além disso, nenhuma interação com o usuário é necessária, basta esolher a função que deseja verificar.

Para acessá-lo, escolha a opção **3** no menu principal:

    +-----------------------------+
    |        MENU PRINCIPAL       |
    +-----------------------------+
    | 1 - Músicas do sistema      |
    | 2 - Playlists               |
    | 3 - Funções sobrecarregadas |
    |                             |
    +-----------------------------+
    | 4 - Sair                    |
    +-----------------------------+
    Digite uma opção: 3

O menu será exibido da seguinte forma:

    +--------------------------------------------+
    |      TESTE DE FUNÇÕES SOBRECARREGADAS      |
    +--------------------------------------------+
    | Novos métodos (Classe Lista)               |
    | 1 - Adicionar elementos (1.A)              |
    | 2 - Remover elementos (1.B)                |
    | 3 - Construtor cópia (1.C)                 |
    |                                            |
    | Sobrecarga de operadores (Classe Lista)    |
    | 4 - Operador "+" (2.A)                     |
    | 5 - Operador de extração ">>" (2.B)        |
    | 6 - Operador de inserção "<<" (2.C)        |
    |                                            |
    | Novos métodos (Classe Playlist)            |
    | 7 - Adicionar músicas (3.A)                |
    | 8 - Remover músicas (3.B)                  |
    | 9 - Construtor cópia (3.C)                 |
    |                                            |
    | Sobrecarga de operadores (Classe Playlist) |
    | 10 - Operador "+" versão 1 (4.A)           |
    | 11 - Operador "+" versão 2 (4.B)           |
    | 12 - Operador "-" versão 1 (4.C)           |
    | 13 - Operador "-" versão 2 (4.D)           |
    | 14 - Operador de extração ">>" (4.E)       |
    | 15 - Operador de inserção "<<" (4.F)       |
    |                                            |
    +--------------------------------------------+
    | 16 - Voltar                                |
    +--------------------------------------------+
    Digite uma opção: 

### Adicionar elementos (1.A)

Este método é uma versão sobrecarregada do método que adiciona um elemento à lista, porém o seu parâmetro é uma outra lista passada por referência. Ao final da operação, todos os elementos da lista recebida serão adicionados à lista atual. Para testar essa função basta escolher a opção **1** no menu de funções sobrecarregadas (linha 707 do main.cpp).

### Remover elementos (1.B)

Este método é uma versão sobrecarregada do método que remove um elemento da lista, porém o seu parâmetro é uma outra lista passada por referência. Ao final da operação, todos os elementos da lista recebida serão removidos da lista atual. Para testar essa função basta escolher a opção **2** no menu de funções sobrecarregadas (linha 769 do main.cpp).

### Construtor cópia (1.C)  

Este é um método especial que recebe como parâmetro uma referência para uma lista e retorna uma cópia da mesma. Ele é útil quando fazemos atribuições entre objetos do tipo lista ou quando retornamos uma lista em uma função, sem fazer alocação dinâmica, por exemplo. Para testar essa função basta escolher a opção **3** no menu de funções sobrecarregadas (linha 827 do main.cpp).

### Operador "+" (2.A)

Este método implementa a concatenação de duas listas, por exemplo, sejam duas listas “A” e “B”, a operação A + B causa que uma nova lista seja criada contendo todas as músicas da lista A, seguido de todas as músicas da lista B, na mesma ordem. Observe que a operação não deve modificar nem a lista “A” nem a lista “B” originais, retornando uma nova lista como resultado. Veja também que essa operação não faz distinção entre os elementos da lista, logo no resultado podem haver elementos repetidos. Para testar essa função basta escolher a opção **4** no menu de funções sobrecarregadas (linha 872 do main.cpp).

### Operador de extração ">>" (2.B)

Este método extrai o último elemento da lista atribuindo seus valores ao nó recebido como argumento. Caso não existam elementos na lista, o valor preenchido no nó recebido pelo operador deve ser `nullptr`. Para testar essa função basta escolher a opção **5** no menu de funções sobrecarregadas (linha 937 do main.cpp).

### Operador de inserção "<<" (2.C)

Este método insere um nó no fim da lista. Caso o valor recebido seja `nullptr`, nada deve ser feito. Para testar essa função basta escolher a opção **6** no menu de funções sobrecarregadas (linha 991 do main.cpp).

### Adicionar músicas (3.A)

Este método é uma versão sobrecarregada do método que adiciona uma música à playlist, porém o seu parâmetro é uma outra PLaylist passada por referência. Ao final da operação todos os elementos da playlist recebida serão adicionados no final da playlist atual. Para testar essa função basta escolher a opção **7** no menu de funções sobrecarregadas (linha 1040 do main.cpp).

### Remover músicas (3.B)

Este método é uma versão sobrecarregada do método que remove uma música da playlist, porém o seu parâmetro é uma outra playlist passada por referência e remove todas as músicas da playlist atual, que estejam na playlist recebida por parâmetro. O método retorna um número com a quantidade de elementos que foram removidos. Para testar essa função basta escolher a opção **8** no menu de funções sobrecarregadas (linha 1107 do main.cpp).

### Construtor cópia (3.C)

Este método é similar ao construtor cópia criado para a lista, porém feito para a playlist. Para testar essa função basta escolher a opção **9** no menu de funções sobrecarregadas (linha 1167 do main.cpp).

### Operador "+" versão 1 (4.A)

Este método implementa a ​união de duas playlists. Diferente da função de concatenação das listas, a união de playlists não permite músicas repetidas na playlist resultante. A operação não deve modificar a playlist original, retornando uma nova playlist como resultado. Para testar essa função basta escolher a opção **10** no menu de funções sobrecarregadas (linha 1217 do main.cpp).

### Operador "+" versão 2 (4.B)

Este método é uma versão sobrecarregada do operador “+”, porém seu parâmetro é uma música passada por referência. Nesse caso, a música deve ser adicionada ao final da playlist que é retornada como resultado do operador (a playlist original continua inalterada). Para testar essa função basta escolher a opção **11** no menu de funções sobrecarregadas (linha 1287 do main.cpp).

### Operador "-" versão 1 (4.C)

Este método implementa a diferença entre duas playlists. Sejam duas playlists A e B, a operação A - B retorna a uma nova playlist contendo todos os elementos da playlist A que não estão na playlist B. Da mesma forma que a operação de união, a playlist original não deve ser modificada após a operação. Para testar essa função basta escolher a opção **12** no menu de funções sobrecarregadas (linha 1340 do main.cpp).

### Operador "-" versão 2 (4.D)

Este método é uma versão sobrecarregada do operador “-”, porém seu parâmetro é uma música passada por referência. Nesse caso, a música deve ser removida da playlist que é retornada como resultado do operador (a playlist original continua inalterada). Para testar essa função basta escolher a opção **13** no menu de funções sobrecarregadas (linha 1410 do main.cpp).

### Operador de extração ">>" (4.E)

Este método remove a última música da playlist atual e preenche seus valores na música recebida por referência no parâmetro. Caso não existam músicas na playlist, `nullptr` deve ser preenchido no parâmetro. Para testar essa função basta escolher a opção **14** no menu de funções sobrecarregadas (linha 1463 do main.cpp).

### Operador de inserção "<<" (4.F)

Este método insere a música recebida por referência no parâmetro na última posição da playlist atual. Caso `nullptr` seja recebido, nada deve ser feito. Para testar essa função basta escolher a opção **15** no menu de funções sobrecarregadas (linha 1511 do main.cpp).

## Limitações do programa

* O sistema tem um limite de armazenamento de playlists pois a estrutura de dados utilizada para armazená-las foi um array. O limite atual de armazenamento é de 20 playlists.

* As funções sobrecarregadas não agem sobre nem manipulam a lista de músicas do sistema e as playlists cadastrada. Nos casos de teste, são utlizadas listas e playlists pré-processadas. 

## Dificuldades e soluções na implementação

* Uma dificuldade encontrada no desenvolvimento durante a primeira etapa do projeto foi a remoção de playlists, dado que o atributo `playlist` da classe `PLaylist` é um ponteiro para uma variável da classe `Lista`. O problema foi resolvido com uma mudança no método `void Playlists::setLista(Lista* lista)`.

* Ao longo da segunda etapa do projeto, houve uma dificuldade na implementação da sobrecarga do `operador+` da classe `Lista`. O main.cpp perdia o acesso às músicas da Lista retornada por `operador+`, visto que era uma variável local do método e quando saía de escopo seu destrutor era chamado, causando o erro "`heap-use-after-free`" identificado pela diretiva `-fsanitaze=address` inserido nos comandos de compilação do programa. A solução para este problema foi alterar o tipo de retorno sugerido para o `operator+` de `Lista` para `Lista*` e armazená-la em uma lista dinamicamente alocada no main.cpp.

---

Desenvolvido por [Diego Filgueiras Balderrama](https://github.com/diegofilbal).
