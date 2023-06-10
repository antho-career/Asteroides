#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"
#include "ElementEspace.h"
#include "Explosion.h"
#include "Espace.h"

class Vaisseau : public ElementEspace
{
    public:
    explicit Vaisseau(Espace& p_espace, sf::Color couleur);
    virtual void reagirCollision(TypeElement typeAutre) override;

    protected:
    virtual void mettreAJour(float temps) override;

    private:
    void actualiserEtat();
    bool accelerationEnCours{false};
    bool tourneAGauche{false};
    bool tourneADroite{false};

    Espace& espace;
    sf::Clock dernierTir{};

    static constexpr float ACCELERATION{7000.f};//on utilise constexpr au lieu de const. En gros constexpr est une const mais dont la valeur doit etre definie a la compilation.
    static constexpr float COEFF_FROTTEMENT{2.f};// ce sont des constantes de classe. partagee entre les objets.
    static constexpr float VITESSE_ANGULAIRE{50.f};
};


#endif // VAISSEAU_H_INCLUDED
