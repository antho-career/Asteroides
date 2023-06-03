#include "Vaisseau.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vecteur.h"

Vaisseau::Vaisseau(sf::Color couleur) : ElementEspace{"ressources/vaisseau.png"}
{
    sprite.setColor(couleur);
}

void Vaisseau::actualiserEtat()
{
    accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    tourneAGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    tourneADroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Vaisseau::mettreAJour(float temps)
{
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
    ElementEspace::mettreAJour(temps);//on appelle la methode de la classe mere ici pour eviter la redondance du code
    explosion.mettreAJour(temps);
}

void Vaisseau::reagirCollision()
{
    if(!detruit)
    {
        detruit = true;
        explosion.demarrer(position);
    }
}

void Vaisseau::afficher(sf::RenderWindow& fenetre)
{
    if(!detruit)
    {
        ElementEspace::afficher(fenetre);
    }
    else
    {
        explosion.afficher(fenetre);
    }
}
