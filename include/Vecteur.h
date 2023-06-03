#ifndef VECTEUR_H
#define VECTEUR_H

//struct est une classe ou tout est publique (classe de donnees dans notre cas car on a besoin
                                              //d acceder aux attributs directement)
struct Vecteur
{
    void operator+=(Vecteur const& autre);
    void operator-=(Vecteur const& autre);
    Vecteur operator*(float coefficient) const;
    static Vecteur creerDepuisAngle(float taille, float angleEnDegre);
    float x{0.f};
    float y{0.f};
};

#endif // VECTEUR_H
