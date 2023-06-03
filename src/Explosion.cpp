#include "Explosion.h"

Explosion::Explosion() : ElementEspace{"ressources/explosion.png"}
{
    //ctor
}

void Explosion::demarrer(Coordonnees const& p_position)
{
    position = p_position;
    demarree = true;
}

void Explosion::mettreAJour(float temps)
{
    if(demarree)
    {
        age += temps;
    }
    if(age < DUREE_VIE)
    {
        sprite.setScale(age/DUREE_VIE, age/DUREE_VIE);
    }
    ElementEspace::mettreAJour(temps);
}

void Explosion::afficher(sf::RenderWindow& fenetre)
{
    if(age < DUREE_VIE)
    {
        ElementEspace::afficher(fenetre);
    }
}

void Explosion::reagirCollision(){} //en realite, ElementEspace devrait etre segmente en 2 parties car reagirCollision n a pas de sens pour l explosion
                                    // nous gardons cette archi pour des raisons de simplicité
