
#include "Date.h"
using namespace std;

bool Date::estBissextile(int a)
{
    if (a % 400 == 0)
        return true;

    if (a % 4 == 0 && a % 100 != 0)
        return true;

    return false;
}

bool Date::estValide(int j, int m, int a)
{
    int joursMois[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (a < 1 || m < 1 || m > 12)
        return false;

    if (estBissextile(a))
        joursMois[1] = 29;

    if (j < 1 || j > joursMois[m - 1])
        return false;

    return true;
}

Date::Date(int j, int m, int a)
{
    if (estValide(j, m, a))
    {
        jour = j;
        mois = m;
        annee = a;
    }
    else
    {
        cerr << "Date invalide !" << endl;

        jour = 1;
        mois = 1;
        annee = 2000;
    }
}

bool Date::operator==(const Date& d) const
{
    if (jour == d.jour &&
        mois == d.mois &&
        annee == d.annee)
        return true;

    return false;
}

bool Date::operator<(const Date& d) const
{
    if (annee < d.annee)
        return true;

    if (annee == d.annee && mois < d.mois)
        return true;

    if (annee == d.annee &&
        mois == d.mois &&
        jour < d.jour)
        return true;

    return false;
}

void Date::consultation() const
{
    cout << jour << "/" << mois << "/" << annee;
}
