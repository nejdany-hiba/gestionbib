
#pragma once

#include <iostream>
#include <string>
#include "Livre.h"

using namespace std;

class Bibliotheque
{
private:
    string nom;
    Livre** livres;
    int nbLivres;
    int capacite;

    static int nbBibliotheques;

public:
    Bibliotheque(string, int);

    Bibliotheque(const Bibliotheque&);

    Bibliotheque& operator=(const Bibliotheque&);

    ~Bibliotheque();

    Livre* ajouterLivre(const Livre&);

    Livre* rechercher(int);

    Livre* rechercher(string);

    void afficherCatalogue() const;

    static int getNbBibliotheques();
};
