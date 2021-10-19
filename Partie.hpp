//
// Created by LI Ningyu on 16/10/2021.
//

#ifndef TP_NOTE_1_PARTIE_HPP
#define TP_NOTE_1_PARTIE_HPP
#include <vector>
#include "Joueur.hpp"
#define GAGNE 0
#define NULLE 1
#define NONTERMINE 2

using namespace std;

class Partie {
private:
    const int piece1, piece2;
    const int ligne, colonne;
    int nbcoup;
    bool tour_joueur1;
    Joueur joueur1, joueur2;
    vector<vector<int> > grille;
public:
    Partie(const Joueur& p, const Joueur& s);
    int get_piece1() const;
    int get_piece2() const;
    int termine();
    void avancer();
    bool get_tour() const;
    void change_tour();
    void calcule_resultat();
    void imprime_grille();
    int get_nbcoup() const;
    int taille_grille() const;
    int get_valeur_case(int, int);
    void set_valeur_case(int, int, int);
};


#endif //TP_NOTE_1_PARTIE_HPP
