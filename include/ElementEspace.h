#ifndef ELEMENTESPACE_H
#define ELEMENTESPACE_H
#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"

class ElementEspace
{
    public:
        explicit ElementEspace(std::string_view const&);
        ElementEspace(ElementEspace const& autre) = delete;//supprime le constructeur de copie, on ne peut plus creer un asteroide a partir d'un autre
        void operator=(ElementEspace const& autre) = delete;//supprime la copie de l'operateur, on ne peut plus copier un asteroide a partir d'un autre
        virtual void mettreAJour(float temps);//methode virtuelle -> pour faire la resolution dynamique de lien (histoire de la liste d elements de classe mere
                                                                                                                 //on veut utiliser la methode de la classe fille.
        virtual void afficher(sf::RenderWindow& fenetre);
        float getRayon() const;
        void testerCollision(ElementEspace& autre) ;//const
        virtual void reagirCollision() = 0;//methode virtuelle pure (utilisee lorsque le methode est uniquement definie dans chaque classe fille) ie: déclaree, mais pas definie.

    protected:
        sf::Texture texture{};
        sf::Sprite sprite{};
        Coordonnees position{};
        Vecteur vitesse{0.f,0.f};
        float vitesseAngulaire{};
};

#endif // ELEMENTESPACE_H
