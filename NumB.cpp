/**
 * Travail realise dans le cadre du cours IFT1166
 * TP1 Partie B
 * Le programme suivant compte et affiche divers statistiques
 *
 */

 /*
  * File:   TP1_1166_NumB_H18.cpp
  * Author: Konstantin Pankratov (1162482)
  *
  * Created on January 10, 2018, 4:48 PM
  */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
 *  ===========================================================================
    Auteur : Konstantin Pankratov
    ---------------------------------------------------------------------------
    But : Cette methode permet d'afficher le contenu  des 4 tableaux.
    ---------------------------------------------------------------------------
    Derniere mise а jour : 2018/01/10
    ---------------------------------------------------------------------------
 *  ===========================================================================
 */
void afficher(int age[], int nbCafe[], char sexe[], float taille[], int nbPers,
    const char message[]) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    // affichage des en-tetes
    cout << "Contenu des 4 tableaux " << message << " :\n";
    cout << "indice      age     cafe   sexe   taille  " << endl;

    // affichage du contenu
    for (int i = 0; i < nbPers; i++)
        cout << setw(3) << i << ") " << setw(10) << age[i]
        << setw(8) << nbCafe[i]
        << setw(6) << sexe[i] << setw(10) << setprecision(2) << taille[i]
        << endl;
    cout << endl;
}

/*
 *  ===========================================================================
    Auteur : Konstantin Pankratov
    ---------------------------------------------------------------------------
    But : Cette methode permet de calculer puis retourner la moyenne d'un
    tableau
    ---------------------------------------------------------------------------
    Derniere mise а jour : 2018/01/10
    ---------------------------------------------------------------------------
 *  ===========================================================================
 */
template <class T>
float moyenne(T tab[], int nbElem) {
    float somme = 0.0;
    for (int i = 0; i < nbElem; i++)
        somme += tab[i];

    return somme / nbElem;
}

/*
 *  ===========================================================================
    Auteur : Konstantin Pankratov
    ---------------------------------------------------------------------------
    But : Cette methode permet de retourner  le nombre d'elements
    correspondants au critere donne d'un tableau
    ---------------------------------------------------------------------------
    Derniere mise а jour : 2018/01/10
    ---------------------------------------------------------------------------
 *  ===========================================================================
 */
template <class T>
int getNbElementsEgal(T tab[], int taille, T element) {
    int nbElements = 0;

    for (int i = 0; i < taille; i++) {
        if (tab[i] == element)
            nbElements++;
    }

    return nbElements;
}

/*
 *  ===========================================================================
    Auteur : Konstantin Pankratov
    ---------------------------------------------------------------------------
    But : Cette methode permet de retourner le nombre d'elements du tableau
    dont la valeur est plus petite que le  critere donne
    ---------------------------------------------------------------------------
    Derniere mise а jour : 2018/01/10
 *  ===========================================================================
 */
template <class T>
int getNbElementsMoinsDe(T tab[], int taille, T element) {
    int nbElements = 0;

    for (int i = 0; i < taille; i++) {
        if (tab[i] < element)
            nbElements++;
    }

    return nbElements;
}

/*
 *  ===========================================================================
    Auteur : Konstantin Pankratov
    ---------------------------------------------------------------------------
    But : Cette methode permet de retourner le nombre d'elements du tableau
    dont la valeur est plus grande que le  critere donne
    ---------------------------------------------------------------------------
    Derniere mise а jour : 2018/01/10
 *  ===========================================================================
 */
template <class T>
int getNbElementsPlusDe(T tab[], int tailleTableau, T element) {
    int nbElements = 0;

    for (int i = 0; i < tailleTableau; i++) {
        if (tab[i] > element)
            nbElements++;
    }

    return nbElements;
}

/*
 *  ===========================================================================
    Auteur : Konstantin Pankratov
    ---------------------------------------------------------------------------
    But : Cette methode permet de retourner la valeur minimum du tableau
    ---------------------------------------------------------------------------
    Derniere mise а jour : 2018/01/10
 *  ===========================================================================
 */
template <class T>
T getMin(T tableau[], int nbElem) {
    T mini;

    mini = tableau[0];

    for (int i = 1; i < nbElem; i++) {
        if (tableau[i] < mini) mini = tableau[i];
    }

    return mini;
}

/*
 *  ===========================================================================
    Methode principale
 *  ===========================================================================
 */
int main_B() {

    // initialisation des tableaux
    int age[] = { 25, 19, 41, 37, 20, 37 },
        nbCafe[] = { 3, 4, 0, 6, 3, 2 };
    char sexe[] = { 'F', 'M', 'F', 'F', 'M', 'F' };
    float taille[] = { 1.72, 1.84, 1.65, 1.57, 1.93, 1.85 };

    // calcul du nombre d'elements du tableau
    int nbPers = sizeof(age) / sizeof(int);

    // compter le nombre de femmes
    int nbFemmes = getNbElementsEgal(sexe, nbPers, 'F');

    // compter le nombre d'hommes
    int nbHommes = getNbElementsEgal(sexe, nbPers, 'M');

    // compter le nombre de personnes de plus de 20 ans
    int nbPersonnesPlus20Ans = getNbElementsPlusDe(age, nbPers, 20);

    // compter le nombre de personnes qui consommes plus de 2 cafes par jour
    int nbPersonnesPlus2Cafes = getNbElementsPlusDe(nbCafe, nbPers, 2);

    // compter le nombre de personnes qui depassent 1.70 metres
    int nbPersonnesPlus170Taille = getNbElementsPlusDe(taille, nbPers, 1.70f);

    // determiner l'age minimum
    int ageMin = getMin(age, nbPers);

    // determiner la consommation du cafe minimum
    int consomCafeMin = getMin(nbCafe, nbPers);

    // determiner la taille minimum
    float tailleMin = getMin(taille, nbPers);


    // afficher le contenu des 4 tableaux
    afficher(age, nbCafe, sexe, taille, nbPers, " au debut");

    // afficher l'age moyen
    cout << "Age moyen : " << setw(6)
        << setprecision(2) << moyenne(age, nbPers) << " an(s) " << endl;

    // afficher la commation moyenne de cafe
    cout << "Consommation moyenne de cafe : " << setw(6)
        << setprecision(2) << moyenne(nbCafe, nbPers)
        << " tasse(s) par jour" << endl;

    // afficher la taille moyenne
    cout << "Taille moyenne : " << setprecision(2)
        << moyenne(taille, nbPers) << " metre" << endl;


    // afficher le nombre de femmes
    cout << "Nombre de Femmes = " << nbFemmes << endl;

    // afficher le nombre d'hommes
    cout << "Nombre d'Hommes = " << nbHommes << endl;

    // afficher le nombre de personnes dont l'age depasse 20 ans
    cout << "Nombre de personnes dont l'age depasse 20 ans = "
        << nbPersonnesPlus20Ans << endl;

    // afficher le nombre dde personnes qui boivent plus de 2 cafes par jour
    cout << "Nombre de personnes qui consomment plus de 2 tasses "
        << "de cafe par jour = " << nbPersonnesPlus2Cafes << endl;

    // afficher le nombre de personnes dont la taille depasse 1.70 metres
    cout << "Nombre de personnes dont la taille depasse 1.70 metres = "
        << nbPersonnesPlus170Taille << endl;

    // afficher l'age minimal
    cout << "Age minimal = " << ageMin << " ans" << endl;

    // afficher la consommation minimale de cafe
    cout << "Consommation minimale de cafe = " << consomCafeMin
        << " tasse(s) par jour" << endl;

    // afficher la taille la plus petite
    cout << "Taille la plus petite = " << tailleMin << " metres" << endl;

    return 0;
}


