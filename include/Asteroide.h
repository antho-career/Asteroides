#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include "ElementEspace.h"

class Asteroide : public ElementEspace
{
    public:
        explicit Asteroide();
        virtual void reagirCollision(TypeElement typeAutre) override;
};

#endif // ASTEROIDE_H
