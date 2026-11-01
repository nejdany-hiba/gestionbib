
#pragma once

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Livre
{
private:
    const int id;
    string titre;
    string auteur;
    Date parution;

    int* notes;
    int nbNotes;
    int cap;

    static int compteurId;
    static int nbInstances;

public:
    Livre(string, string, Date, int);

    Livre(const Livre&);

    Livre& operator=(const Livre&);

    ~Livre();

    void ajouterNote(int);

    double calculerMoyenne() const;

    void afficher() const;

    int getId() const;

    string getTitre() const;

    static int getNbInstances();
};
