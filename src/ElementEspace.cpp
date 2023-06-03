#include "ElementEspace.h"
#include <iostream>

ElementEspace::ElementEspace(std::string_view const& cheminImage)
{
    if (! texture.loadFromFile(cheminImage.data()))
    {
        std::cerr << "Image " << cheminImage << " n'a pas ete correctement chargee!!" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(position.getX(),position.getY());
}

void ElementEspace::mettreAJour(float temps)
{
    auto deplacement = vitesse*temps;
    position += deplacement;
    sprite.setPosition(position.getX(),position.getY());
    sprite.rotate(vitesseAngulaire*temps);
}

void ElementEspace::afficher(sf::RenderWindow& fenetre)
{
    auto affichages = std::array<Vecteur,9>{Vecteur{-1, -1},Vecteur{0, -1},Vecteur{1, -1},
                                            Vecteur{-1, 0},Vecteur{0, 0},Vecteur{1, 0},
                                            Vecteur{-1, 1},Vecteur{0, 1},Vecteur{1, 1}};
    for(auto& affichage : affichages)
    {
        auto transformation = sf::Transform{};
        transformation.translate(affichage.x*Coordonnees::getLongueurEspace(), affichage.y*Coordonnees::getHauteurEspace());
        fenetre.draw(sprite, transformation);
    }
}

float ElementEspace::getRayon() const
{
    return sprite.getLocalBounds().height/2.f;
}

void ElementEspace::testerCollision(ElementEspace& autre)
{
    auto distance = position.calculerDistance(autre.position);
    if (distance < getRayon() + autre.getRayon())
    {
        reagirCollision();
        //sprite.setColor(sf::Color::Red);
        //autre.sprite.setColor(sf::Color::Red);
    }
}
