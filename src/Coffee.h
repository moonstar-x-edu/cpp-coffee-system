#ifndef CPP_COFFEE_SYSTEM_COFFEE_H
#define CPP_COFFEE_SYSTEM_COFFEE_H

#include <string>
#include "Enums.h"

using namespace std;

class Coffee {
    private:
        string name;
        Beans beans;
        Size size;
        double basePrice;
        bool hasSugar;
        bool hasCocoa;
        bool hasCinnamon;
        bool hasMilk;
        bool hasCream;

    public:
        Coffee(string name, Beans beans, Size size, double basePrice);

        string getName();
        string getBeans();
        string getSize();
        double getPrice();
        bool getSugar();
        bool getCocoa();
        bool getCinnamon();
        bool getMilk();
        bool getCream();

        void addSugar();
        void addCocoa();
        void addCinnamon();
        void addMilk();
        void addCream();
};

#endif //CPP_COFFEE_SYSTEM_COFFEE_H
