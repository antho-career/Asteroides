#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"
#include "ElementEspace.h"
#include "Explosion.h"

class Vaisseau : public ElementEspace
{
    public:
    explicit Vaisseau(sf::Color couleur);
    void actualiserEtat();
    virtual void mettreAJour(float temps) override;
    virtual void reagirCollision() override;
    virtual void afficher(sf::RenderWindow& fenetre) override;

    private:
    bool accelerationEnCours{false};
    bool tourneAGauche{false};
    bool tourneADroite{false};
    bool detruit{false};

    Explosion explosion{};

    static constexpr float ACCELERATION{7000.f};//on utilise constexpr au lieu de const. En gros constexpr est une const mais dont la valeur doit etre definie a la compilation.
    static constexpr float COEFF_FROTTEMENT{2.f};// ce sont des constantes de classe. partagee entre les objets.
    static constexpr float VITESSE_ANGULAIRE{50.f};
};


#endif // VAISSEAU_H_INCLUDED
