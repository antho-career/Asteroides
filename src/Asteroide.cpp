#include "Asteroide.h"
#include <iostream>
#include <random>

Asteroide::Asteroide() : ElementEspace{"ressources/asteroide.png"}
{
    auto generateur = std::random_device{};
    auto distributionPosition = std::uniform_real_distribution<float>{-150.0f,150.0f};
    auto distributionVitesse = std::uniform_real_distribution<float>{80.0f,120.0f};
    auto distributionAngle = std::uniform_real_distribution<float>{0.0f,360.0f};
    auto distributionVitesseAngulaire = std::uniform_real_distribution<float>{10.0f,30.0f};
    position = {distributionPosition(generateur),distributionPosition(generateur)};
    vitesse = Vecteur::creerDepuisAngle(distributionVitesse(generateur),distributionAngle(generateur));
    vitesseAngulaire = distributionVitesseAngulaire(generateur);

    std::cout << "positionX asteroide: " << position.getX() << "positionY asteroide: " << position.getY() << std::endl;
}

void Asteroide::reagirCollision()
{

}
