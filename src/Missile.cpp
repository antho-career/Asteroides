#include "Missile.h"

Missile::Missile(Coordonnees const& p_position, float rotation) : ElementEspace{"ressources/missile.png"}
{
    type = TypeElement::MISSILE;
    position = p_position;
    sprite.setRotation(rotation);
    vitesse = Vecteur::creerDepuisAngle(VITESSE, rotation);
}

void Missile::reagirCollision(TypeElement typeAutre)
{
    if(typeAutre == TypeElement::ASTEROIDE)
    {
        detruit = true;
    }
}
