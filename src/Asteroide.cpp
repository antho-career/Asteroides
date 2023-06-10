#include "Asteroide.h"
#include <iostream>
#include <random>

Asteroide::Asteroide() : ElementEspace{"ressources/asteroide.png"}
{
    type = TypeElement::ASTEROIDE;
    auto generateur = std::random_device{};
    auto distributionPosition = std::uniform_real_distribution<float>{-150,150};
    auto distributionVitesse = std::uniform_real_distribution<float>{80,120};
    auto distributionAngle = std::uniform_real_distribution<float>{0,360};
    auto distributionVitesseAngulaire = std::uniform_real_distribution<float>{10,30};
    position = {distributionPosition(generateur),distributionPosition(generateur)};
    vitesse = Vecteur::creerDepuisAngle(distributionVitesse(generateur),distributionAngle(generateur));
    vitesseAngulaire = distributionVitesseAngulaire(generateur);

    std::cout << "positionX asteroide: " << position.getX() << "positionY asteroide: " << position.getY() << std::endl;
}

void Asteroide::reagirCollision(TypeElement typeAutre)
{

}
