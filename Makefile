CPP=g++ --std=c++11
CFLAGS= -Wall

all : tournoi

tournoi : main.o Tournoi.o Partie.o Joueur.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

tournoi.o : Tournoi.cpp Tournoi.hpp
	$(CPP) $(CFLAGS) -c $<

partie.o : Partie.cpp Partie.hpp
	$(CPP) $(CFLAGS) -c $<

joueur.o : Joueur.cpp Joueur.hpp
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o

test: all
	cat test_3J test_4J | ./tournoi
