all:
	gcc -Wall -Wextra -I include \
	src/main.c \
	src/gestion_personnes.c \
	src/gestion_fichier.c \
	-o bin/gestionnaire

clean :
	rm -f bin/gestionnaire

run: all
	./bin/gestionnaire