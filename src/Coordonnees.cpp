#include "Coordonnees.h"
#include <iostream>
#include <cmath>
#include <algorithm>

int Coordonnees::longueurEspace{0};
int Coordonnees::hauteurEspace{0};

Coordonnees::Coordonnees()
{
    if(longueurEspace==0 || hauteurEspace==0)
    {
        std::cerr << "Attention : une coordonnee a ete creee avant initilisation de l espace!" << std::endl;
    }
    else
    {
        x = 400;
        y = 300;
        recalculer();
    }
}

Coordonnees::Coordonnees(float px, float py) : x(px), y(py)
{
    recalculer();
}

void Coordonnees::operator+=(Vecteur const& vecteur)
{
    x += vecteur.x;
    y += vecteur.y;
    recalculer();
}

void Coordonnees::initialiserEspace(int longueur, int hauteur)
{
    if(longueurEspace != 0 || hauteurEspace != 0)
    {
        std::cerr << "Attention : l espace etait deja initialise !" << std::endl;
    }
    longueurEspace = longueur;
    hauteurEspace = hauteur;
}

void Coordonnees::recalculer()
{
    while(x>longueurEspace)
    {
        x -= longueurEspace;
    }
    while(x<0)
    {
        x += longueurEspace;
    }
    while(y>hauteurEspace)
    {
        y -= hauteurEspace;
    }
    while(y<0)
    {
        y += hauteurEspace;
    }
}

float Coordonnees::calculerDistance(Coordonnees const& autre) const
{
    auto delta = Vecteur{std::min({abs(x-autre.x), abs(x-autre.x-longueurEspace), abs(x-autre.x+longueurEspace)}),std::min({abs(y-autre.y), abs(y-autre.y-longueurEspace), abs(y-autre.y+longueurEspace)})};
    return std::sqrt(delta.x*delta.x+delta.y*delta.y);

}
