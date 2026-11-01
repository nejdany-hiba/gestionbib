
#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Bibliotheque.h"

using namespace std;

int main()
{
    Date d1(10, 5, 2020);
    Date d2(15, 6, 2022);
    Date d3(20, 9, 2024);

    cout << "=== TEST DATE ===" << endl;

    d1.consultation();
    cout << endl;

    if (d1 < d2)
        cout << "d1 est avant d2" << endl;

    if (d1 == d2)
        cout << "Dates egales" << endl;
    else
        cout << "Dates differentes" << endl;

    cout << "\n=== CREATION LIVRES ===" << endl;

    Livre l1("C++", "Ali", d1, 5);
    Livre l2("POO", "Sara", d2, 4);
    Livre l3("Algorithmique", "Ahmed", d3, 3);

    cout << "\n=== AJOUT NOTES ===" << endl;

    l1.ajouterNote(15);
    l1.ajouterNote(18);
    l1.ajouterNote(16);

    l2.ajouterNote(12);
    l2.ajouterNote(17);

    l3.ajouterNote(14);
    l3.ajouterNote(19);

    cout << "\n=== AFFICHAGE LIVRES ===" << endl;

    l1.afficher();
    l2.afficher();
    l3.afficher();

    cout << "\n=== BIBLIOTHEQUE ===" << endl;

    Bibliotheque b1("Bibliotheque FSTM", 3);

    Livre* livre1 = b1.ajouterLivre(l1);
    Livre* livre2 = b1.ajouterLivre(l2);
    Livre* livre3 = b1.ajouterLivre(l3);

    b1.afficherCatalogue();

    cout << "\n=== RECHERCHE PAR TITRE ===" << endl;

    Livre* r1 = b1.rechercher("POO");

    if (r1 != nullptr)
        r1->afficher();
    else
        cout << "Livre introuvable !" << endl;

    cout << "\n=== RECHERCHE PAR ID ===" << endl;

    if (livre1 != nullptr)
    {
        Livre* r2 = b1.rechercher(livre1->getId());

        if (r2 != nullptr)
            r2->afficher();
        else
            cout << "Livre introuvable !" << endl;
    }

    cout << "\n=== RECHERCHE INFRUCTUEUSE ===" << endl;

    Livre* r3 = b1.rechercher("Java");

    if (r3 != nullptr)
        r3->afficher();
    else
        cout << "Livre introuvable !" << endl;

    cout << "\n=== TEST CAPACITE ===" << endl;

    Livre l4("Python", "Omar", d1, 5);

    Livre* resultat = b1.ajouterLivre(l4);

    if (resultat == nullptr)
        cout << "Impossible : bibliotheque pleine !" << endl;

    cout << "\n=== STATISTIQUES ===" << endl;

    cout << "Nombre de livres existants : "
        << Livre::getNbInstances() << endl;

    cout << "Nombre de bibliotheques : "
        << Bibliotheque::getNbBibliotheques() << endl;

    cout << "\n=== RECOPIE LIVRE ===" << endl;

    Livre copie(l1);
    copie.afficher();

    cout << "\n=== AFFECTATION LIVRE ===" << endl;

    Livre l5("Ancien titre", "Auteur", d1, 4);

    l5 = l2;
    l5.afficher();

    cout << "\n=== FIN DU PROGRAMME ===" << endl;

    return 0;
}
