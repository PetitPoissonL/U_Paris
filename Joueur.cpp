//
// Created by 李宁豫 on 16/10/2021.
//

#include "Joueur.hpp"
#include <cmath>

using namespace std;

Joueur::Joueur(const string& n) : name(n), scores_tournoi(0), scores_total(0){}

float Joueur::get_scores_tournoi() const{
    return scores_tournoi;
}

float Joueur::get_scores_total() const{
    return scores_total;
}

void Joueur::set_scores_tournoi(int nbc) {
    scores_tournoi += (float)9/((float)nbc + fmodf((float)nbc,(float)2));
}

void Joueur::set_scores_total(int nbc) {
    scores_total += (float)9/((float)nbc + fmodf((float)nbc,(float)2));
}

string Joueur::get_name() {
    return name;
}

void Joueur::initialise_scores_tournoi() {
    scores_tournoi = 0;
}