# YourJam
Bem vindo ao *YourJam*, um sistema de gerenciamento de músicas e playlists implementado em C++!


## Instalando e executando
Com o terminal aberto no diretório em que deseja baixar o projeto, digite:

    $ git clone https://github.com/diegofilbal/YourJam.git

Entre no diretório do projeto com:

    $ cd YourJam

E para compilar e executar o programa, digite:

    $ make run

## Como usar o sistema

### Músicas do sistema
Para entrar no menu de músicas do sistema, digite **1** no Menu principal:

    +---------------------------+
    |      MENU PRINCIPAL       |
    +---------------------------+
    | 1 - Músicas do sistema    |
    | 2 - Playlists             |
    | 3 - Músicas das playlists |
    | 4 - Tocar música          |
    | 5 - Sair                  |
    +---------------------------+
    Digite uma opção: 1

O seguinte menu aparecerá na tela:

    +--------------------------------+ 
    |       MUSICAS DO SISTEMA       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Exibir músicas cadastradas |
    | 4 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 

#### Adicionar músicas ao sistema
Para adicionar uma música no sistema, escolha a opção **1** no menu de músicas do sistema.

    +--------------------------------+ 
    |       MUSICAS DO SISTEMA       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Exibir músicas cadastradas |
    | 4 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 1

Logo em seguida, digite o nome e o artista da música da música e informe se deseja inserir a música em alguma posição expecífica da lista:

    Digite o nome da música:
    Blinding Lights

    Digite o nome do artista:
    The Weeknd

    Deseja incluir em alguma posição específica? Não(1) ou Sim(2)?
    1

    Música cadastrada no sistema com sucesso!
    Pressione ENTER para continuar...

Se desejar inserir a música em uma posição específica da lista, basta escolher a opção **2** depois de digitar o nome e artista da música:

    Digite o nome da música:
    Golden

    Digite o nome do artista:
    Harry Styles

    Deseja incluir em alguma posição específica? Não(1) ou Sim(2)?
    2


Logo em seguida, aparecerá uma tela com as playlists cadastradas. Insira a posição em que deseja inserir a música:

    1. Blinding Lights - The Weeknd

    Digite a posição:
    1

    Música cadastrada no sistema com sucesso!
    Pressione ENTER para continuar...

#### Remover músicas do sistema
Para remover uma música, escolha a opção **2** no menu de músicas do sistema:

    +--------------------------------+ 
    |       MUSICAS DO SISTEMA       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Exibir músicas cadastradas |
    | 4 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 2

Uma lista enumerada das músicas cadastradas no sistema aparecerá e você deve digitar o número da música que deseja remover do sistema:

    1. Golden - Harry Styles
    2. Blinding Lights - The Weeknd
    3. Like I Want You - Giveon
    4. After Hours - The Weeknd

    Digite o número da música que deseja remover do sistema:
    1

    Música removida do sistema com sucesso!
    Pressione ENTER para continuar...

#### Listar músicas do sistema
Para ver todas as músicas cadastradas, digite **3** no menu de músicas do sistema:

    +--------------------------------+ 
    |       MUSICAS DO SISTEMA       |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Exibir músicas cadastradas |
    | 4 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 3

A lista de músicas cadastradas aparecerá de forma enumerada na tela da seguinte forma:

    1. Blinding Lights - The Weeknd
    2. Like I Want You - Giveon
    3. After Hours - The Weeknd

    Pressione ENTER para continuar...

### Playlists
Para entrar no menu de playlists, digite **2** no Menu principal:

    +---------------------------+
    |      MENU PRINCIPAL       |
    +---------------------------+
    | 1 - Músicas do sistema    |
    | 2 - Playlists             |
    | 3 - Músicas das playlists |
    | 4 - Tocar música          |
    | 5 - Sair                  |
    +---------------------------+
    Digite uma opção: 2

O seguinte menu aparecerá na tela:

    +------------------------+
    |       PLAYLISTS        |
    +------------------------+
    | 1 - Adicionar playlist |
    | 2 - Remover playlist   |
    | 3 - Exibir playlists   |
    | 4 - Voltar             |
    +------------------------+
    Digite uma opção:

#### Adicionar playlists
Para adicionar uma playlist, escolha a opção **1** no menu de playlists.

    +------------------------+
    |       PLAYLISTS        |
    +------------------------+
    | 1 - Adicionar playlist |
    | 2 - Remover playlist   |
    | 3 - Exibir playlists   |
    | 4 - Voltar             |
    +------------------------+
    Digite uma opção: 1


Logo em seguida, digite o nome que deseja dar à playlist:

    Digite o nome da playlist que deseja inserir:
    Musicas Favoritas

    Playlist Musicas Favoritas adicionada com sucesso!
    Pressione ENTER para continuar...

#### Remover playlists
Para remover uma playlist, escolha a opção **2** no menu de playlists:

    +------------------------+
    |       PLAYLISTS        |
    +------------------------+
    | 1 - Adicionar playlist |
    | 2 - Remover playlist   |
    | 3 - Exibir playlists   |
    | 4 - Voltar             |
    +------------------------+
    Digite uma opção: 2

Uma lista enumerada das playlists cadastradas no sistema aparecererá e você deve digitar o número da playlist que deseja apagar:

    1. Musicas Favoritas
    2. Workout
    3. Para dormir

    Digite o número da playlist que deseja remover:
    2

    Playlist removida com sucesso!
    Pressione ENTER para continuar...

#### Listar playlists
Para ver todas as playlists cadastradas, digite **3** no menu de playlists:

    +------------------------+
    |       PLAYLISTS        |
    +------------------------+
    | 1 - Adicionar playlist |
    | 2 - Remover playlist   |
    | 3 - Exibir playlists   |
    | 4 - Voltar             |
    +------------------------+
    Digite uma opção: 3

A lista de playlists cadastradas aparecerá de forma enumerada na tela da seguinte forma:

    1. Musicas Favoritas
    2. Para dormir

    Pressione ENTER para continuar...

---

### Músicas das playlists
Para abrir o menu de músicas das playlists, escolha a opção **3** no menu princpal:

    +---------------------------+
    |      MENU PRINCIPAL       |
    +---------------------------+
    | 1 - Músicas do sistema    |
    | 2 - Playlists             |
    | 3 - Músicas das playlists |
    | 4 - Tocar música          |
    | 5 - Sair                  |
    +---------------------------+
    Digite uma opção: 3

Logo em seguida, escolha a playlist que deseja abrir:

    1 - Musicas Favoritas
    2 - Para dormir

    Digite o número da playlist que deseja abrir:
    1

#### Adicionar músicas à playlist
Para adicionar uma música à playlist, escolha a opção **1** no menu de músicas das playlists:

    +--------------------------------+
    |     MÚSICAS DAS PLAYLISTS      |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Mover música               |
    | 4 - Exibir músicas da playlist |
    | 5 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 1

Em seguida, uma lista enumerada das músicas do sistema aparecerá na tela e você deve digitar a posição da música que deseja adicionar à playlist, bem como informar se deseja adicioná-la em uma posição específica da playlist:

    1. Blinding Lights - The Weeknd
    2. Like I Want You - Giveon
    3. After Hours - The Weeknd


    Digite a posição da música que deseja adicionar em Musicas Favoritas:
    2

    Deseja adicionar esta música em uma posição específica de Musicas Favoritas? Não(1) ou Sim(2)
    1

Se desejar adicionar a música em uma posição específica da playlist, basta escolher a opção 2 depois de digitar o número da música:

    1. Blinding Lights - The Weeknd
    2. Like I Want You - Giveon
    3. After Hours - The Weeknd


    Digite a posição da música que deseja adicionar em Musicas Favoritas:
    3

    Deseja adicionar esta música em uma posição específica de Musicas Favoritas? Não(1) ou Sim(2)
    1

Uma lista das músicas da playlist aparecerá de forma enumerada na tela, em seguida digite a posição em eu deseja adicionar a música:

    1. Like I Want You - Giveon

    Digite a posição em que deseja inserir a música: 
    1

    Música adicionada na playlist com sucesso!
    Pressione ENTER para continuar...

#### Remover músicas da playlist
Para remover uma música da playlist, escolha a opção **2** do menu de músicas das playlists:

    +--------------------------------+
    |     MÚSICAS DAS PLAYLISTS      |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Mover música               |
    | 4 - Exibir músicas da playlist |
    | 5 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 2

Em seguida, uma lista das músicas dessa playlist aparecerá de forma enumerada e você deve digitar o número da música que deseja remover da playlist:

    1. After Hours - The Weeknd
    2. Like I Want You - Giveon

    Digite o número da música que deseja remover da playlist:
    2

    Música removida com sucesso!
    Pressione ENTER para continuar...

#### Mover músicas da playlist
Para mover uma música dentro de uma playlist, ou seja, trocá-la de posição, escolha a opção **3** do menu de músicas das playlists:

    +--------------------------------+
    |     MÚSICAS DAS PLAYLISTS      |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Mover música               |
    | 4 - Exibir músicas da playlist |
    | 5 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 3

Uma lista das músicas dessa playlist aparecerá de forma enumerada na tela e você deve informar o número da música que deseja mover e a posição para qual deseja que ela seja movida, repectivavamente:

    1. After Hours - The Weeknd
    2. Like I Want You - Giveon

    Digite a posição atual da música que deseja mover:
    2
    Digite a posição para qual deseja mover:
    1

Em seguida, será exibido na tela a nova ordem das músicas na tela:

    Música movida com sucesso!

    1. Like I Want You - Giveon
    2. After Hours - The Weeknd

    Pressione ENTER para continuar...

#### Exibir músicas da playlist
Para exibir todas as músicas dessa playlist, escolha a opção **4** do menu de músicas das playlists:

    +--------------------------------+
    |     MÚSICAS DAS PLAYLISTS      |
    +--------------------------------+
    | 1 - Adicionar música           |
    | 2 - Remover música             |
    | 3 - Mover música               |
    | 4 - Exibir músicas da playlist |
    | 5 - Voltar                     |
    +--------------------------------+
    Digite uma opção: 4

Logo em seguida, a lista de músicas da playlist aparecerá na tela:

    1. Like I Want You - Giveon
    2. After Hours - The Weeknd

    Pressione ENTER para continuar...

### Tocar música
Para tocar uma música, escolha a opção **4** do menu principal:

    +---------------------------+
    |      MENU PRINCIPAL       |
    +---------------------------+
    | 1 - Músicas do sistema    |
    | 2 - Playlists             |
    | 3 - Músicas das playlists |
    | 4 - Tocar música          |
    | 5 - Sair                  |
    +---------------------------+
    Digite uma opção: 4

Em seguida, digite o número da playlist de onde deseja reproduzir as músicas:

    1 - Musicas Favoritas
    2 - Para dormir

    Digite o número da playlist que deseja reproduzir:
    1

Logo após, música que está sendo reproduzida no momento é informada na tela:

    Tocando Like I Want You - Giveon da playlist Musicas Favoritas!

É possível tocar músicas de uma playlist até que a última música seja reproduzida.


### Limitações e dificuldades

O sistema tem um limite de armazenamento de playlists pois a estrutura de dados utilizada para armazená-las foi um array. O limite atual de armazenamento é de 20 playlists.

Uma dificuldade encontrada no desenvolvimento foi a remoção de playlists, dado que o atributo `playlist` da classe `PLaylist` é um ponteiro para uma variável da classe `Lista`. O problema foi resolvido com uma mudança no método `void Playlists::setLista(Lista* lista)`.

---

Desenvolvido por [Diego Filgueiras Balderrama](https://github.com/diegofilbal).