#ifndef COORDONNEES_H
#define COORDONNEES_H

#include "Vecteur.h"

class Coordonnees
{
    public:
        static void initialiserEspace(int longueur, int hauteur);
        static inline int getLongueurEspace() {return longueurEspace;};
        static inline int getHauteurEspace() {return longueurEspace;};
        Coordonnees();
        Coordonnees(float px, float py);
        inline float getX() const {return x;};
        inline float getY() const {return y;};
        void operator+=(Vecteur const& vecteur);
        float calculerDistance(Coordonnees const& autre) const;

    private:
        void recalculer();//privee car inutile d y acceder depuis l exterieur
        float x{longueurEspace/2.f};
        float y{longueurEspace/2.f};

        //static car partages par tous les objets
        static int longueurEspace;
        static int hauteurEspace;
};

#endif // COORDONNEES_H
