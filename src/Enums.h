#ifndef CPP_COFFEE_SYSTEM_ENUMS_H
#define CPP_COFFEE_SYSTEM_ENUMS_H

#include <string>
#include <map>
#include <exception>

using namespace std;

using CoffeeExtras = map<string, bool>;

enum Beans {
    Arabic,
    Colombian,
    Bitter
};

enum Size {
    Small,
    Medium,
    Large,
    ExtraLarge
};

string getBeansString(Beans beans);
string getSizeString(Size size);
float getSizePriceMultiplier(Size size);

#endif //CPP_COFFEE_SYSTEM_ENUMS_H
