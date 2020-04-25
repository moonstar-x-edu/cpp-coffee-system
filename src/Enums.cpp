#include "Enums.h"

string getBeansString(Beans beans) {
    switch (beans) {
        case Arabic:
            return "Arabic";
        case Colombian:
            return "Colombian";
        case Bitter:
            return "Bitter";
        default:
            throw "Invalid Beans enum value!";
    }
}

string getSizeString(Size size) {
    switch (size) {
        case Small:
            return "Small";
        case Medium:
            return "Medium";
        case Large:
            return "Large";
        case ExtraLarge:
            return "Extra Large";
        default:
            throw "Invalid Size enum value!";
    }
}
