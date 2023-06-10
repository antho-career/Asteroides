#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Vaisseau.h"
#include "Asteroide.h"
#include "Espace.h"

using namespace std;

constexpr int LONGUEUR_FENETRE(800);
constexpr int HAUTEUR_FENETRE(600);
const sf::Color COULEUR_VAISSEAU{sf::Color{128,255,128}};

int main()
{
    sf::RenderWindow fenetre(sf::VideoMode(LONGUEUR_FENETRE, HAUTEUR_FENETRE), "Asteroid");
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE, HAUTEUR_FENETRE);
    auto espace = Espace{};
    //auto pointeurVaisseau = std::unique_ptr<Vaisseau>{nullptr};//pointeur dans la tas initialise a null


    auto partieDemarree{false};
    //auto chrono = sf::Clock();
    while (fenetre.isOpen())
    {
        auto evenement = sf::Event{};
        while (fenetre.pollEvent(evenement))
        {
            if (evenement.type == sf::Event::Closed)
                fenetre.close();
            if(evenement.type == sf::Event::KeyPressed && !partieDemarree)
            {
                espace.ajouter(std::make_unique<Vaisseau>(espace, COULEUR_VAISSEAU));
                espace.ajouter(std::make_unique<Asteroide>());
                //espace.ajouter(std::make_unique<Asteroide>());
                //espace.ajouter(std::make_unique<Asteroide>());
                //ici, pas besoins d utiliser la methode move car on cree le vaisseau directement
                //sans passer par une variable intermediaire. Idem pour les asteroides.
                partieDemarree = true;
            }
        }
        espace.actualiser();
        espace.gererCollisions();
        espace.nettoyer();
        fenetre.clear();
        espace.afficher(fenetre);
        fenetre.display();
    }
    return 0;
}
