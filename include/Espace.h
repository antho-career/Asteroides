#ifndef ESPACE_H
#define ESPACE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "ElementEspace.h"
class Espace
{
    public:
        Espace();
        void ajouter(std::unique_ptr<ElementEspace> element);
        void actualiser();
        void gererCollisions();
        void afficher(sf::RenderWindow& fenetre);
        void nettoyer();

    protected:

    private:
        std::vector<std::unique_ptr<ElementEspace>> elements{};
        sf::Clock chrono{};
};

#endif // ESPACE_H
