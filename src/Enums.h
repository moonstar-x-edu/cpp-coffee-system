#ifndef CPP_COFFEE_SYSTEM_ENUMS_H
#define CPP_COFFEE_SYSTEM_ENUMS_H

#include <string>
#include <exception>

using namespace std;

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

#endif //CPP_COFFEE_SYSTEM_ENUMS_H
