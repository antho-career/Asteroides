#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vaisseau.h"
#include "Asteroide.h"

using namespace std;

constexpr int LONGUEUR_FENETRE(800);
constexpr int HAUTEUR_FENETRE(600);
const sf::Color COULEUR_VAISSEAU{sf::Color{128,255,128}};

int main()
{
    sf::RenderWindow fenetre(sf::VideoMode(LONGUEUR_FENETRE, HAUTEUR_FENETRE), "Asteroid");
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE, HAUTEUR_FENETRE);
    auto vaisseau = Vaisseau{COULEUR_VAISSEAU};
    auto asteroide = Asteroide{};
    auto asteroide2 = Asteroide{};
    auto asteroide3 = Asteroide{};
    auto elements = std::array<ElementEspace*,4>{&asteroide, &asteroide2, &asteroide3, &vaisseau};
    auto chrono = sf::Clock();
    while (fenetre.isOpen())
    {
        auto evenement = sf::Event{};
        while (fenetre.pollEvent(evenement))
        {
            if (evenement.type == sf::Event::Closed)
                fenetre.close();
        }
        vaisseau.actualiserEtat();
        auto tempsBoucle = chrono.restart().asSeconds();
        for (auto* element : elements)
        {
            element->actualiser(tempsBoucle);
        }
        for (auto* element : elements)
        {
            for (auto* element2 : elements)
            {
                if(element != element2)
                {
                    element->testerCollision(*element2);
                }
            }
        }
        fenetre.clear();
        for (auto* element : elements)
        {
            element->afficher(fenetre);
        }
        fenetre.display();
    }
    return 0;
}
