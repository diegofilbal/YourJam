# Compila todos os arquivos e gera o executável
all: create_dir main

# Cria pasta para armazenar os arquivos objetos
create_dir:
	mkdir -p bin

# Compila o arquivo musica.cpp e gera o arquivo objeto musica.o
bin/musica.o: src/musica.cpp
	g++ src/musica.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/musica.o

# Compila o arquivo node.cpp e gera o arquivo objeto node.o
bin/node.o: src/node.cpp bin/musica.o
	g++ src/node.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/node.o

# Compila o arquivo lista.cpp e gera o arquivo objeto lista.o
bin/lista.o: src/lista.cpp bin/node.o
	g++ src/lista.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/lista.o

# Compila o arquivo playlist.cpp e gera o arquivo objeto playlist.o
bin/playlist.o: src/playlist.cpp bin/lista.o
	g++ src/playlist.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/playlist.o

# Compila o arquivo main.cpp, gera o arquivo objeto main.o e o executável
bin/main.o: src/main.cpp bin/playlist.o
	g++ src/main.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/main.o

# Cria o arquivo executável
main: bin/main.o
	g++ bin/*.o -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -o main

# Executa o programa
run: all
	./main

# Apaga a pasta de arquivos objetos e o executável
clean:
	rm -rf bin main