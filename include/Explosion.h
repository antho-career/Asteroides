#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <ElementEspace.h>


class Explosion : public ElementEspace
{
    public:
        Explosion();
        void demarrer(Coordonnees const& p_position);
        virtual void mettreAJour(float temps) override;
        virtual void reagirCollision() override;
        virtual void afficher(sf::RenderWindow& fenetre) override;

    protected:

    private:
        bool demarree{false};
        float age{};
        static constexpr float DUREE_VIE{0.1f};
};

#endif // EXPLOSION_H
