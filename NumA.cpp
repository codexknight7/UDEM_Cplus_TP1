/**
 * Travail realise dans le cadre du cours IFT1166
 * TP1 Partie A
 * Le programme suivant affiche les diviseurs de 17 et 20
 *
 */

 /*
  * File:   TP1_1166_NumA_H18.cpp
  * Author: Konstantin Pankratov (1162482)
  *
  * Created on January 10, 2018, 4:48 PM
  */

#include <cstdlib>
#include <iostream>

using namespace std;

/// Compte et retourne le nombre de diviseurs d'un nombre
/// \param nombre
/// \return 
int getNbDiviseurs(int nombre) {
    int nbDiviseurs = 0;

    for (int i = 1; i <= nombre; i++) {
        if (nombre % i == 0)
            nbDiviseurs++;
    }
    return nbDiviseurs;
}

/// Affiche la liste des diviseurs d'un nombre
/// \param nombre
void afficheDiviseurs(int nombre) {
    int compteur = 0;

    for (int i = 1; i <= nombre; i++) {
        if (nombre % i == 0) {
            cout << ++compteur << ") " << i;
            cout << endl;
        }
    }
}

/// Programme principal
/// \return 
int main_A() {
    // declaration des variables
    int nbDiviseurs_17 = 0;
    int nbDiviseurs_20 = 0;

    // obtention du nombre de diviseurs
    nbDiviseurs_17 = getNbDiviseurs(17);
    nbDiviseurs_20 = getNbDiviseurs(20);

    // affichage des resultats
    cout << "Les " << nbDiviseurs_17 << " diviseurs de 17:\n";
    afficheDiviseurs(17);

    cout << "Les " << nbDiviseurs_20 << " diviseurs de 20:\n";
    afficheDiviseurs(20);

    return 0;
}