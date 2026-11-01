
#include "Bibliotheque.h"
#include <iostream>
using namespace std;

int Bibliotheque::nbBibliotheques = 0;

Bibliotheque::Bibliotheque(string n, int c)
    : nom(n), livres(nullptr), nbLivres(0), capacite(c)
{
    if (capacite < 0)
        capacite = 0;

    livres = new Livre * [capacite];

    for (int i = 0; i < capacite; i++)
        livres[i] = nullptr;

    nbBibliotheques++;
}

Bibliotheque::Bibliotheque(const Bibliotheque& b)
    : nom(b.nom), livres(nullptr),
    nbLivres(0), capacite(b.capacite)
{
    livres = new Livre * [capacite];

    for (int i = 0; i < capacite; i++)
        livres[i] = nullptr;

    for (int i = 0; i < b.nbLivres && i < capacite; i++)
    {
        livres[i] = new Livre(*b.livres[i]);
        nbLivres++;
    }

    nbBibliotheques++;
}

Bibliotheque& Bibliotheque::operator=(const Bibliotheque& b)
{
    if (this != &b)
    {
        Livre** nouveau = new Livre * [b.capacite];

        for (int i = 0; i < b.capacite; i++)
            nouveau[i] = nullptr;

        for (int i = 0; i < b.nbLivres && i < b.capacite; i++)
            nouveau[i] = new Livre(*b.livres[i]);

        for (int i = 0; i < nbLivres; i++)
            delete livres[i];

        delete[] livres;

        nom = b.nom;
        livres = nouveau;
        nbLivres = b.nbLivres;
        capacite = b.capacite;
    }

    return *this;
}

Bibliotheque::~Bibliotheque()
{
    for (int i = 0; i < nbLivres; i++)
        delete livres[i];

    delete[] livres;

    nbBibliotheques--;
}

Livre* Bibliotheque::ajouterLivre(const Livre& l)
{
    if (nbLivres >= capacite)
    {
        cout << "Bibliotheque pleine !" << endl;
        return nullptr;
    }

    livres[nbLivres] = new Livre(l);
    nbLivres++;

    return livres[nbLivres - 1];
}

Livre* Bibliotheque::rechercher(int id)
{
    for (int i = 0; i < nbLivres; i++)
    {
        if (livres[i]->getId() == id)
            return livres[i];
    }

    return nullptr;
}

Livre* Bibliotheque::rechercher(string titre)
{
    for (int i = 0; i < nbLivres; i++)
    {
        if (livres[i]->getTitre() == titre)
            return livres[i];
    }

    return nullptr;
}

void Bibliotheque::afficherCatalogue() const
{
    cout << "Bibliotheque : " << nom << endl;

    for (int i = 0; i < nbLivres; i++)
        livres[i]->afficher();
}

int Bibliotheque::getNbBibliotheques()
{
    return nbBibliotheques;
}
