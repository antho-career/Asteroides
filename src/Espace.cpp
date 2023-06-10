#include "Espace.h"

Espace::Espace()
{
    //ctor
}

void Espace::ajouter(std::unique_ptr<ElementEspace> element)
{
    elements.push_back(std::move(element));
    //on deplace le pointeur donc, il n est plus valide.
    //Rem: on ne peut pas copier un pointeur unique. Il ne peut
    //cohexister 2 pointeurs uniques qui pointent vers la meme adresse
    //mais on peut deplacer un pointeur unique vers un autre en utilisant
    //la fonction std::move
}

void Espace::actualiser()
{
    auto tempsBoucle = chrono.restart().asSeconds();
    for(auto i{0u}; i<elements.size();++i)
    {
        elements[i]->actualiser(tempsBoucle);
    }
}

void Espace::gererCollisions()
{
    for (auto i{0u}; i<elements.size();++i)
    {
        for (auto j{0u}; j<elements.size(); ++j)
        {
            if(i != j)
            {
                elements[i]->testerCollision(*elements[j]);
            }
        }
    }
    // /!\ avec la methode pushback, les iterateurs ne sont pas garantis de fonctionner.
    // on preferera oublier la methode avec ":" et utiliser la boucle for classique avec
    // increment d un indice. i{0u} dit au compilo qu il s agit d un entier unsigned int
    //donc un entier positif.
}

void Espace::afficher(sf::RenderWindow& fenetre)
{
    for(auto& element : elements)
    {
        element->afficher(fenetre);
    }
}

void Espace::nettoyer()
{
    auto finTableau = std::remove_if(std::begin(elements), std::end(elements),ElementEspace::estDetruit);
    elements.erase(finTableau,std::end(elements));
}

