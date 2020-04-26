#ifndef CPP_COFFEE_SYSTEM_COFFEEDIRECTOR_H
#define CPP_COFFEE_SYSTEM_COFFEEDIRECTOR_H

#include "CoffeeBuilder.h"

class CoffeeDirector {
    private:
        CoffeeBuilder builder;
        void handleAddExtras(CoffeeExtras extras);

    public:
        CoffeeDirector();

        Coffee makeEspresso(Size size, CoffeeExtras extras);
        Coffee makeLatte(Size size, CoffeeExtras extras);
        Coffee makeMocha(Size size, CoffeeExtras extras);
        Coffee makeCapuccino(Size size, CoffeeExtras extras);
};

#endif //CPP_COFFEE_SYSTEM_COFFEEDIRECTOR_H
