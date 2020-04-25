#ifndef CPP_COFFEE_SYSTEM_COFFEEBUILDER_H
#define CPP_COFFEE_SYSTEM_COFFEEBUILDER_H

#include "Coffee.h"

class CoffeeBuilder {
    private:
        Coffee* result;

    public:
        CoffeeBuilder();

        void setName(string name);
        void setBeans(Beans beans);
        void setSize(Size size);
        void setBasePrice(double basePrice);
        void withSugar();
        void withCocoa();
        void withCinnamon();
        void withMilk();
        void withCream();

        Coffee getResult();
        void reset();
};

#endif //CPP_COFFEE_SYSTEM_COFFEEBUILDER_H
