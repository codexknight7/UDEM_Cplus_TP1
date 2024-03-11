/**
 * Travail realise dans le cadre du cours IFT1166
 * TP1 Partie C
 * Le programme suivant compte et affiche divers statistiques
 *
 */

 /*
  * File:   TP1_1166_NumC_H18.cpp
  * Author: Konstantin Pankratov (1162482)
  *
  * Created on January 10, 2018, 4:48 PM
  */


  /* Fichier tp1_1166_numC_H18.cpp pour le numero C du Tp1 IFT 1166

     Numero C du TP1 : 10 points

     Ajouter des fonctions et leurs appels afin de :
     1. afficher le contenu de ces 4 tableaux avant le tri;
     2. rechercher et afficher les resultats de la
        recherche des personnes ayant de numeros suivants :
              2233, 4177, 9876
        par la recherche sequentielle dans le tableau
        des numeros non tries

     3. determiner et afficher toutes les informations
           a) d'une personne ayant la taille la plus grande
           b) d'une personne ayant le poids le plus lourd
     4. calculer et afficher
           a) la taille moyenne des femmes
           b) le poids moyen des hommes
     5. trier (avec le tri par selection) les personnes selon leurs
        numeros et afficher le contenu de ces 4 tableaux
        apres le tri;
     6. rechercher et afficher les resultats de la
        recherche des personnes ayant de numeros suivants :
              2233, 4177, 9876
        par la recherche sequentielle dans le tableau des numeros tries


      Criteres de correction :
          6 x 1 point pour le bon fonctionnement
          4 points pour la qualite du code

      Total de 10 points
   */

#include <iostream>  // pour entree-sortie  cin, cout
#include <iomanip>   // pour le formatage
#include <fstream>   // pour les fichiers


using namespace std; // librairie standard

/* cette fonction est expliquee en classe :
   Elle permet de lire le fichier e partir de son nom,
   de remplir les 4 tableaux et de transmettre via
   pointeur le nombre de personnes lues.
 */
void lireRemplir(const char nomALire[], int numero[], char sexe[],
    float taille[], float poids[], int* p) {
    const float PIED_EN_METRE = 0.3048,
        LIVRE_EN_KG = 0.454;
    int nbPieds, nbPouces, nbLivres;

    ifstream aLire(nomALire, ios::in); // localiser et ouvrir pour la lecture

    int n = 0; // initialiser le compteur

    while (aLire >> sexe[n] >> numero[n] >> nbPieds >> nbPouces >> nbLivres) {
        taille[n] = (nbPieds + nbPouces / 12.0) * PIED_EN_METRE;
        poids[n] = nbLivres * LIVRE_EN_KG;
        n++;
    }
    aLire.close();
    *p = n;
}

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
void afficher(int numero[], char sexe[], float taille[],
    float poids[], int nbPers, const char message[]) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    cout << "Contenu des 4 tableaux " << message << ":\n";
    cout << "indice      numero     sexe   taille   poids  " << endl;


    for (int i = 0; i < nbPers; i++) {
        cout << setw(3) << i << ") "
            << setw(12) << numero[i]
            << setw(8) << sexe[i]
            << setw(10) << setprecision(2) << taille[i]
            << setw(9) << setprecision(2) << poids[i]
            << endl;
        cout << endl;
    }
}

/*
 *  ===========================================================================
    Auteur : Konstantin Pankratov
    ---------------------------------------------------------------------------
    But : Cette methode permet de permuter les 2 elements d'un tableau
    ---------------------------------------------------------------------------
    Derniere mise а jour : 2018/01/10
    ---------------------------------------------------------------------------
 *  ===========================================================================
 */
template <class T>
void permuter(T* p1, T* p2) {
    T tempo = *p1;
    *p1 = *p2;
    *p2 = tempo;
}

/*
 *  ===========================================================================
    Auteur : Konstantin Pankratov
    ---------------------------------------------------------------------------
    But : Cette methode permet de trier les tableaux selon le numero
    de personne
    ---------------------------------------------------------------------------
    Derniere mise а jour : 2018/01/10
    ---------------------------------------------------------------------------
 *  ===========================================================================
 */
void trier(int numero[], char sexe[], float taille[], float poids[],
    int nbPers) {
    for (int i = 0; i < nbPers - 1; i++) {
        int indMin = i;
        for (int j = i + 1; j < nbPers; j++)
            if (numero[j] < numero[indMin])
                indMin = j;
        if (indMin != i) // on permute les elements des tableaux
        {
            permuter(&numero[i], &numero[indMin]);
            permuter(&sexe[i], &sexe[indMin]);
            permuter(&taille[i], &taille[indMin]);
            permuter(&poids[i], &poids[indMin]);
        }
    }
}

/*
 *  ===========================================================================
    Auteur : Konstantin Pankratov
    ---------------------------------------------------------------------------
    But : Cette methode permet de determiner la valeur maximum d'un tableau
    ---------------------------------------------------------------------------
    Derniere mise а jour : 2018/01/10
    ---------------------------------------------------------------------------
 *  ===========================================================================
 */
template <class T>
T maxi(T tab[], int nbElem) {
    T plusGrand = tab[0];
    for (int i = 1; i < nbElem; i++)
        if (tab[i] > plusGrand)
            plusGrand = tab[i];
    return plusGrand;
}

/*
 *  ===========================================================================
    Auteur : Konstantin Pankratov
    ---------------------------------------------------------------------------
    But : Cette methode permet de trouver la moyenne des valeurs d'un tableau
    selon le sexe voulu
    ---------------------------------------------------------------------------
    Derniere mise а jour : 2018/01/10
    ---------------------------------------------------------------------------
 *  ===========================================================================
 */
template <class T>
void determiner(T tableau[], int nbElem, char sexe[],
    char sexeVoulu, float& moyenne) {
    T somme = tableau[0];
    int nbSexeVoulu = 0;

    for (int i = 0; i < nbElem; i++) {
        if (sexeVoulu == sexe[i]) {
            nbSexeVoulu++;
            somme += tableau[i];
        }
    }

    moyenne = somme / nbSexeVoulu;
}

/*
 *  ===========================================================================
    Methode principale
 *  ===========================================================================
 */
int main() {

    /* declaration de 4 tableaux et du nombre de personnes lues
       qui est aussi le nombre d'elements de ces 4 tableaux */
    const int MAX_PERS = 25;
    int numero[MAX_PERS], numeroTrouve[MAX_PERS];
    char sexe[MAX_PERS], sexeTrouve[MAX_PERS];
    float taille[MAX_PERS], poids[MAX_PERS];
    float tailleTrouve[MAX_PERS], poidsTrouve[MAX_PERS];
    int nbPers, nbPersTrouve = 0;
    int j = 0;
    float moyenne;


    // lire et remplir les tableaux a partir d'un fichier
    lireRemplir("imp_h18.txt", numero, sexe, taille, poids, &nbPers);
    cout << "On vient de lire les informations de "
        << nbPers << " personnes\n\n";


    //  ======================================================================= 
    //  1 - afficher le contenu des tableaux avant le tri
    //  ======================================================================= 
    afficher(numero, sexe, taille, poids, nbPers, "avant le tri");

    //  ======================================================================= 
    //  2 - rechercher et afficher les resultats de la
    //  recherche des personnes ayant de numeros suivants : 2233, 4177, 9876
    //  par la recherche sequentielle dans le tableau des numeros non tries
    //  ======================================================================= 
    for (int i = 0; i < nbPers; i++) {
        if ((numero[i] == 2233) || (numero[i] == 4177) || (numero[i] == 9876)) {
            numeroTrouve[j] = numero[i];
            sexeTrouve[j] = sexe[i];
            tailleTrouve[j] = taille[i];
            poidsTrouve[j] = poids[i];
            j++;
            nbPersTrouve++;
        }
    }
    afficher(numeroTrouve, sexeTrouve, tailleTrouve, poidsTrouve,
        nbPersTrouve, "numeros: 2233, 4177, 9876 non tries");

    //  ======================================================================= 
    //   3 - determiner et afficher toutes les informations
    //   a) d'une personne ayant la taille la plus grande
    //   b) d'une personne ayant le poids le plus lourd
    //  =======================================================================     

    // taille max
    float tailleMax = maxi(taille, nbPers);

    // poids max
    float poidsMax = maxi(poids, nbPers);

    // afficher les personnes avec taille max
    j = 0;
    nbPersTrouve = 0;
    for (int i = 0; i < nbPers; i++) {
        if (taille[i] == tailleMax) {
            numeroTrouve[j] = numero[i];
            sexeTrouve[j] = sexe[i];
            tailleTrouve[j] = taille[i];
            poidsTrouve[j] = poids[i];
            j++;
            nbPersTrouve++;
        }
    }
    afficher(numeroTrouve, sexeTrouve, tailleTrouve, poidsTrouve,
        nbPersTrouve, "personne avec taille MAX");

    // afficher les personnes avec poids max
    j = 0;
    nbPersTrouve = 0;
    for (int i = 0; i < nbPers; i++) {
        if (poids[i] == poidsMax) {
            numeroTrouve[j] = numero[i];
            sexeTrouve[j] = sexe[i];
            tailleTrouve[j] = taille[i];
            poidsTrouve[j] = poids[i];
            j++;
            nbPersTrouve++;
        }
    }
    afficher(numeroTrouve, sexeTrouve, tailleTrouve, poidsTrouve,
        nbPersTrouve, "personne avec poids MAX");

    //  ======================================================================= 
    //  4 - calculer et afficher
    //  a) la taille moyenne des femmes
    //  b) le poids moyen des hommes
    //  =======================================================================     
    determiner(taille, nbPers, sexe, 'F', moyenne);
    cout << "Taille moyenne des Femmes = " << moyenne << " metres" << endl;

    determiner(poids, nbPers, sexe, 'M', moyenne);
    cout << "Poids moyen des Hommes = " << moyenne << " kg\n" << endl;

    //  =======================================================================     
    //  5 - trier (avec le tri par selection) les personnes selon leurs
    //  numeros et afficher le contenu de ces 4 tableaux apres le tri
    //  =======================================================================      
    trier(numero, sexe, taille, poids, nbPers);
    afficher(numero, sexe, taille, poids, nbPers, "apres le tri");

    //  =======================================================================       
    //  6 - rechercher et afficher les resultats de la recherche 
    //  des personnes ayant de numeros suivants : 2233, 4177, 9876
    //  par la recherche sequentielle dans le tableau des numeros tries
    //  =======================================================================     
    j = 0;
    nbPersTrouve = 0;
    for (int i = 0; i < nbPers; i++) {
        if ((numero[i] == 2233) || (numero[i] == 4177) || (numero[i] == 9876)) {
            numeroTrouve[j] = numero[i];
            sexeTrouve[j] = sexe[i];
            tailleTrouve[j] = taille[i];
            poidsTrouve[j] = poids[i];
            j++;
            nbPersTrouve++;
        }
    }
    afficher(numeroTrouve, sexeTrouve, tailleTrouve, poidsTrouve,
        nbPersTrouve, "numeros: 2233, 4177, 9876 tries");

    // fin
    return 0;
}
