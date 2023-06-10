#include "Explosion.h"

Explosion::Explosion(Coordonnees const& p_position) : ElementEspace{"ressources/explosion.png"}
{
    type = TypeElement::AUTRE;
    position = p_position;
}

void Explosion::mettreAJour(float temps)
{
    age += temps;
    if(age < DUREE_VIE)
    {
        sprite.setScale(age/DUREE_VIE, age/DUREE_VIE);
    }
    else
    {
        detruit = true;
    }
    //ElementEspace::mettreAJour(temps); //plus besoin maintenant
}

void Explosion::reagirCollision(TypeElement typeAutre){} //en realite, ElementEspace devrait etre segmente en 2 parties car reagirCollision n a pas de sens pour l explosion
                                    // nous gardons cette archi pour des raisons de simplicité
