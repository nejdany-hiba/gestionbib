
#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
    int jour;
    int mois;
    int annee;

public:
    static bool estBissextile(int);
    static bool estValide(int, int, int);

    Date(int j = 1, int m = 1, int a = 2000);

    bool operator==(const Date&) const;
    bool operator<(const Date&) const;

    void consultation() const;
};
