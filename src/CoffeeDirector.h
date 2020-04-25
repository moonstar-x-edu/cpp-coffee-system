#ifndef CPP_COFFEE_SYSTEM_COFFEEDIRECTOR_H
#define CPP_COFFEE_SYSTEM_COFFEEDIRECTOR_H

#include "CoffeeBuilder.h"

class CoffeeDirector {
    private:
        CoffeeBuilder builder;

    public:
        CoffeeDirector();

        Coffee makeEspresso();
        Coffee makeLatte();
        Coffee makeMocha();
        Coffee makeCapuccino();
};

#endif //CPP_COFFEE_SYSTEM_COFFEEDIRECTOR_H
