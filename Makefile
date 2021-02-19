# Compila todos os arquivos e gera o executável
all: musica.o node.o lista.o playlist.o main.o
	g++ musica.o node.o lista.o playlist.o main.o -o main

# Compila o arquivo musica.cpp e gera o arquivo objeto musica.o
musica.o: musica.cpp
	g++ -O0 -g -Wall -ansi -pedantic -std=c++11 -c musica.cpp

# Compila o arquivo node.cpp e gera o arquivo objeto node.o
node.o: node.cpp musica.o
	g++ -O0 -g -Wall -ansi -pedantic -std=c++11 -c node.cpp

# Compila o arquivo lista.cpp e gera o arquivo objeto lista.o
lista.o: lista.cpp musica.o node.o
	g++ -O0 -g -Wall -ansi -pedantic -std=c++11 -c lista.cpp

# Compila o arquivo playlist.cpp e gera o arquivo objeto playlist.o
playlist.o: playlist.cpp musica.o node.o lista.o
	g++ -O0 -g -Wall -ansi -pedantic -std=c++11 -c playlist.cpp

# Compila o arquivo main.cpp, gera o arquivo objeto main.o e o executável
main.o: main.cpp musica.o node.o lista.o playlist.o
	g++ -O0 -g -Wall -ansi -pedantic -std=c++11 -c main.cpp

# Executa o programa
run: musica.o node.o lista.o playlist.o main.o all
	./main

# Apaga o executável e os arquivos objetos
clean:
	rm -rf *.o main