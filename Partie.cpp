//
// Created by LI Ningyu on 16/10/2021.
//

#include "Partie.hpp"
#include "Joueur.hpp"
#include <iostream>
#include <vector>

using namespace std;

Partie::Partie(const Joueur& p, const Joueur& s) : piece1(1), piece2(2), ligne(3), colonne(3), nbcoup(0), tour_joueur1(true), joueur1(p), joueur2(s), grille(ligne,vector<int>(colonne, 0)){}

int Partie::get_piece1() const {
    return piece1;
};

int Partie::get_piece2() const {
   return piece2;
};

bool Partie::get_tour() const {
    return tour_joueur1;
}

int Partie::termine() {
    bool ligne0 = (get_valeur_case(0,0) == get_valeur_case(0,1)) && (get_valeur_case(0,0) == get_valeur_case(0,2)) && (get_valeur_case(0,0) > 0);
    bool ligne1 = (get_valeur_case(1,0) == get_valeur_case(1,1)) && (get_valeur_case(1,0) == get_valeur_case(1,2)) && (get_valeur_case(1,0) > 0);
    bool ligne2 = (get_valeur_case(2,0) == get_valeur_case(2,1)) && (get_valeur_case(2,0) == get_valeur_case(2,2)) && (get_valeur_case(2,0) > 0);
    bool colonne0 = (get_valeur_case(0,0) == get_valeur_case(1,0)) && (get_valeur_case(0,0) == get_valeur_case(2,0)) && (get_valeur_case(0,0) > 0);
    bool colonne1 = (get_valeur_case(0,1) == get_valeur_case(1,1)) && (get_valeur_case(0,1) == get_valeur_case(2,1)) && (get_valeur_case(2,1) > 0);
    bool colonne2 = (get_valeur_case(0,2) == get_valeur_case(1,2)) && (get_valeur_case(0,2) == get_valeur_case(2,2)) && (get_valeur_case(0,2) > 0);
    bool diagonal1 = (get_valeur_case(0,0) == get_valeur_case(1,1)) && (get_valeur_case(0,0) == get_valeur_case(2,2)) && (get_valeur_case(0,0) > 0);
    bool diagonal2 = (get_valeur_case(0,2) == get_valeur_case(1,1)) && (get_valeur_case(0,2) == get_valeur_case(2,0)) && (get_valeur_case(0,2) > 0);
    bool gagne = ligne0 || ligne1 || ligne2 || colonne0 || colonne1 || colonne2 || diagonal1 || diagonal2;
    if (gagne)
        return GAGNE;
    else if (nbcoup == taille_grille())
        return NULLE;
    else
        return NONTERMINE;
}

void Partie::imprime_grille() {
    for(int i=0; i<ligne; i++){
        for(int j=0; j<colonne; j++)
            cout << get_valeur_case(i,j) << " ";
        cout << endl;
    }
}

void Partie::calcule_resultat() {
    if(termine() == GAGNE){
        if(!tour_joueur1) {
            cout << "--> Bravo Joueur " << joueur1.get_name() << "!!!" << endl;
            joueur1.set_scores_tournoi(get_nbcoup());
            joueur1.set_scores_total(get_nbcoup());
        }
        else {
            cout << "--> Bravo Joueur " << joueur2.get_name() << "!!!" << endl;
            joueur2.set_scores_tournoi(get_nbcoup());
            joueur2.set_scores_total(get_nbcoup());
        }
    }
    if(termine() == NULLE){
        cout << "--> Partie nulle" << endl;
    }
    cout << "scores du joueur " << joueur1.get_name() << ": tournoi " << joueur1.get_scores_tournoi() << ", total " << joueur1.get_scores_total() << endl;
    cout << "scores du joueur " << joueur2.get_name() << ": tournoi " << joueur2.get_scores_tournoi() << ", total " << joueur2.get_scores_total() << endl;
    cout << endl;
}

void Partie::change_tour() {
    tour_joueur1 = !tour_joueur1;
}

void Partie::avancer() {
    change_tour();
    nbcoup++;
}

int Partie::get_nbcoup() const {
    return nbcoup;
}

int Partie::taille_grille() const {
    return ligne*colonne;
}

int Partie::get_valeur_case(int i, int j) {
    return grille[i][j];
}

void Partie::set_valeur_case(int i, int j, int valeur) {
    grille[i][j] = valeur;
}