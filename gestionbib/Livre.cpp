
#include "Livre.h"
using namespace std;

int Livre::compteurId = 0;
int Livre::nbInstances = 0;


Livre::Livre(string t, string a, Date d, int c)
    : id(++compteurId),
    titre(t),
    auteur(a),
    parution(d),
    notes(nullptr),
    nbNotes(0),
    cap(c)
{
    if (cap < 0)
        cap = 0;

    notes = new int[cap];

    nbInstances++;

    cout << "Construction livre : "
        << titre << endl;
}


Livre::Livre(const Livre& l)
    : id(++compteurId),
    titre(l.titre),
    auteur(l.auteur),
    parution(l.parution),
    notes(nullptr),
    nbNotes(l.nbNotes),
    cap(l.cap)
{
    notes = new int[cap];

    for (int i = 0; i < nbNotes; i++)
    {
        notes[i] = l.notes[i];
    }

    nbInstances++;

    cout << "Recopie livre : "
        << titre << endl;
}


Livre& Livre::operator=(const Livre& l)
{
    if (this != &l)
    {
        int* nouveau = new int[l.cap];

        for (int i = 0; i < l.nbNotes; i++)
        {
            nouveau[i] = l.notes[i];
        }

        titre = l.titre;
        auteur = l.auteur;
        parution = l.parution;

        delete[] notes;

        notes = nouveau;
        nbNotes = l.nbNotes;
        cap = l.cap;
    }

    return *this;
}


Livre::~Livre()
{
    delete[] notes;

    nbInstances--;

    cout << "Destruction livre : "
        << titre << endl;
}


void Livre::ajouterNote(int n)
{
    if (n < 0 || n > 20)
    {
        cout << "Note invalide !" << endl;
        return;
    }

    if (nbNotes >= cap)
    {
        cout << "Capacite des notes atteinte !"
            << endl;
        return;
    }

    notes[nbNotes] = n;
    nbNotes++;

    cout << "Note ajoutee : " << n << endl;
}


double Livre::calculerMoyenne() const
{
    if (nbNotes == 0)
        return 0;

    double somme = 0;

    for (int i = 0; i < nbNotes; i++)
    {
        somme = somme + notes[i];
    }

    return somme / nbNotes;
}

void Livre::afficher() const
{
    cout << "----------------------" << endl;

    cout << "ID : " << id << endl;
    cout << "Titre : " << titre << endl;
    cout << "Auteur : " << auteur << endl;

    cout << "Date de parution : ";
    parution.consultation();
    cout << endl;

    cout << "Nombre de notes : "
        << nbNotes << endl;

    cout << "Notes : ";

    for (int i = 0; i < nbNotes; i++)
    {
        cout << notes[i] << " ";
    }

    cout << endl;

    cout << "Moyenne : "
        << calculerMoyenne() << endl;
}

int Livre::getId() const
{
    return id;
}

string Livre::getTitre() const
{
    return titre;
}

int Livre::getNbInstances()
{
    return nbInstances;
}
