//
// Created by LI Ningyu on 16/10/2021.
//

#ifndef TP_NOTE_1_JOUEUR_HPP
#define TP_NOTE_1_JOUEUR_HPP
#include <string>

using namespace std;

class Joueur {
private:
    string name;
    float scores_tournoi;
    float scores_total;
public:
    explicit Joueur(const string& n);
    float get_scores_tournoi() const;
    float get_scores_total() const;
    void set_scores_tournoi(int nbc);
    void set_scores_total(int nbc);
    string get_name();
    /* Pour un nouveau tournoi, il faut initialiser le score de tournoi pour les participants. */
    void initialise_scores_tournoi();
};

#endif //TP_NOTE_1_JOUEUR_HPP
