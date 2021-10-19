//
// Created by LI Ningyu on 16/10/2021.
//

#ifndef TP_NOTE_1_TOURNOI_HPP
#define TP_NOTE_1_TOURNOI_HPP
#include "Joueur.hpp"
#include <vector>

class Tournoi {
private:
    vector<Joueur> participants;
    bool statut_inscription;
public:
    Tournoi();
    void inscription(const Joueur& j);
    /* Quand on lance un tournoi, on fais C(2,nbjoueurs) fois parties, par exp: 3 joueur C(2,3)= 3 fois parties, 4 3 joueur C(2,4)= 6 fois parties */
    void lance_tournoi();
    void vide_participants();
    int nb_joueur();
    void resultat_total();
    /* chercher le score tournoi max quand le tournoi termine */
    float score_max();
    /* Quand on lance un tournoi, il ne peut pas faire une nouvel inscription. */
    void change_statut_inscri();
};

#endif //TP_NOTE_1_TOURNOI_HPP
