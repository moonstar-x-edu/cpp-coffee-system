#ifndef CPP_COFFEE_SYSTEM_COFFEE_H
#define CPP_COFFEE_SYSTEM_COFFEE_H

#include <string>
#include "Enums.h"
#include "IJSONizable.h"

using namespace std;

class Coffee : public IJSONizable {
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
        Coffee();
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

        void setName(string name);
        void setBeans(Beans beans);
        void setSize(Size size);
        void setBasePrice(double basePrice);
        void addSugar();
        void addCocoa();
        void addCinnamon();
        void addMilk();
        void addCream();

        json toJSON() override;

        string toString();
};

#endif //CPP_COFFEE_SYSTEM_COFFEE_H
