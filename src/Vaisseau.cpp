#include "Vaisseau.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Missile.h"

Vaisseau::Vaisseau(Espace& p_espace, sf::Color couleur) : ElementEspace{"ressources/vaisseau.png"}, espace{p_espace}
{
    type = TypeElement::VAISSEAU;
    sprite.setColor(couleur);
}

void Vaisseau::actualiserEtat()
{
    accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    tourneAGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    tourneADroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (dernierTir.getElapsedTime().asSeconds() > 0,1))
    {
        espace.ajouter(std::make_unique<Missile>(position, sprite.getRotation()));
        dernierTir.restart();
    }
}

void Vaisseau::mettreAJour(float temps)
{
    actualiserEtat();
    if(!detruit)
    {
        if(accelerationEnCours)
        {
            vitesse += Vecteur::creerDepuisAngle(ACCELERATION*temps, sprite.getRotation());
        }
        vitesse -= vitesse*COEFF_FROTTEMENT*temps;

        if(tourneAGauche)
        {
            vitesseAngulaire = -VITESSE_ANGULAIRE;
        }
        else if(tourneADroite)
        {
            vitesseAngulaire = VITESSE_ANGULAIRE;
        }
        else
        {
            vitesseAngulaire = 0;
        }
    }
    //ElementEspace::mettreAJour(temps);//on appelle la methode de la classe mere ici pour eviter la redondance du code
    //plus besoin maintenant.
    //explosion.actualiser(temps);//on ajoutera l explosion a l espace
}

void Vaisseau::reagirCollision(TypeElement typeAutre)
{
    if(typeAutre == TypeElement::ASTEROIDE)
    {
        detruit = true;
        espace.ajouter(std::make_unique<Explosion>(position));
    }
}
