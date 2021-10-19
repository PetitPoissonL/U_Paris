//
// Created by LI Ningyu on 16/10/2021.
//

#include "Tournoi.hpp"
#include "Joueur.hpp"
#include "Partie.hpp"
#include <iostream>
#include <string>

using namespace std;

Tournoi::Tournoi() : participants(), statut_inscription(true){}

int Tournoi::nb_joueur() {
    return (int)participants.size();
}

void Tournoi::inscription(const Joueur& j){
    if(statut_inscription){
        participants.push_back(j);
    }
}

void Tournoi::change_statut_inscri() {
    statut_inscription = !statut_inscription;
}

void Tournoi::vide_participants(){
    participants.clear();
}

float Tournoi::score_max() {
    float max = participants[0].get_scores_total();
    for(int i=1; i<nb_joueur(); i++){
        if(max < participants[i].get_scores_total())
            max = participants[i].get_scores_total();
    }
    return max;
}

void Tournoi::resultat_total() {
    cout << "Le(s) gagnants du tournoi sont :" << endl;
    for(int i=0; i<nb_joueur(); i++){
        if(participants[i].get_scores_total() == score_max()) {
            cout << participants[i].get_name() << endl;
        }
    }
    cout << "avec le score " << score_max() << endl;
    cout << endl;
    cout << "Scores totaux des participants :" << endl;
    for(int j=0; j<nb_joueur(); j++){
        cout << "scores du joueur " << participants[j].get_name() << ": tournoi " << participants[j].get_scores_tournoi() << ", total "<< participants[j].get_scores_total() << endl;
    }
}

void Tournoi::lance_tournoi(){
    change_statut_inscri();
    for(int n=0; n<participants.size(); n++){
        participants[n].initialise_scores_tournoi();
    }
    //lire l'entrée de fichier ligne par ligne, chaque ligne est une partie
    for(int i=0; i<nb_joueur()-1; i++){
        for(int j=i+1; j<nb_joueur(); j++){
            if(!cin.eof()) {
                string jeu;
                getline(cin, jeu);
                Partie p(participants[i], participants[j]);
                cout << "Partie entre " << participants[i].get_name() << " et " << participants[j].get_name() << endl;
                for (int k = 0; k < jeu.size(); k += 4) {
                    if (p.get_tour())
                        p.set_valeur_case((jeu[k] - '0'), (jeu[k + 2] - '0'), p.get_piece1());
                    else
                        p.set_valeur_case((jeu[k] - '0'), (jeu[k + 2] - '0'), p.get_piece2());
                    cout << "Entrez une case (" << jeu[k] << ", " << jeu[k + 2] << ")" << endl;
                    p.avancer();
                    p.imprime_grille();
                }
                p.calcule_resultat();
            }
        }
    }
    resultat_total();
    change_statut_inscri();
}