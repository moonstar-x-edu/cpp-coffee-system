#include "Coffee.h"

Coffee::Coffee() {
    this->name = "Coffee";
    this->beans = Arabic;
    this->size = Small;
    this->basePrice = 2.5;
    this->hasSugar = false;
    this->hasCocoa = false;
    this->hasCinnamon = false;
    this->hasMilk = false;
    this->hasCream = false;
}

Coffee::Coffee(string name, Beans beans, Size size, double basePrice) {
    this->name = name;
    this->beans = beans;
    this->size = size;
    this->basePrice = basePrice;
    this->hasSugar = false;
    this->hasCocoa = false;
    this->hasCinnamon = false;
    this->hasMilk = false;
    this->hasCream = false;
}

string Coffee::stringifyExtras() {
    string extras;

    if (this->hasSugar) {
        extras += " sugar,";
    }
    if (this->hasCocoa) {
        extras += " cocoa,";
    }
    if (this->hasCinnamon) {
        extras += " cinnamon,";
    }
    if (this->hasMilk) {
        extras += " milk,";
    }
    if (this->hasCream) {
        extras += " cream,";
    }

    if (!extras.empty()) {
        extras = " with:" + extras;
        extras.pop_back();
    }

    return extras;
}

string Coffee::getName() {
    return this->name;
}

string Coffee::getBeans() {
    return getBeansString(this->beans);
}

string Coffee::getSize() {
    return getSizeString(this->size);
}

double Coffee::getPrice() {
    double price = this->basePrice * getSizePriceMultiplier(this->size);

    if (this->hasSugar) {
        price += SUGAR_PRICE;
    }
    if (this->hasCocoa) {
        price += COCOA_PRICE;
    }
    if (this->hasCinnamon) {
        price += CINNAMON_PRICE;
    }
    if (this->hasMilk) {
        price += MILK_PRICE;
    }
    if (this->hasCream) {
        price += CREAM_PRICE;
    }

    return price;
}

bool Coffee::getSugar() {
    return this->hasSugar;
}

bool Coffee::getCocoa() {
    return this->hasCocoa;
}

bool Coffee::getCinnamon() {
    return this->hasCinnamon;
}

bool Coffee::getMilk() {
    return this->hasMilk;
}

bool Coffee::getCream() {
    return this->hasCream;
}

void Coffee::setName(string name) {
    this->name = name;
}

void Coffee::setBeans(Beans beans) {
    this->beans = beans;
}

void Coffee::setSize(Size size) {
    this->size = size;
}

void Coffee::setBasePrice(double basePrice) {
    this->basePrice = basePrice;
}

void Coffee::addSugar() {
    this->hasSugar = true;
}

void Coffee::addCocoa() {
    this->hasCocoa = true;
}

void Coffee::addCinnamon() {
    this->hasCinnamon = true;
}

void Coffee::addMilk() {
    this->hasMilk = true;
}

void Coffee::addCream() {
    this->hasCream = true;
}

json Coffee::toJSON() {
    json j;

    j["name"] = this->getName();
    j["beans"] = this->getBeans();
    j["size"] = this->getSize();
    j["price"] = formatDoubleTwoDecimal(this->getPrice());
    j["extras"]["sugar"] = this->getSugar();
    j["extras"]["cocoa"] = this->getCocoa();
    j["extras"]["cinnamon"] = this->getCinnamon();
    j["extras"]["milk"] = this->getMilk();
    j["extras"]["cream"] = this->getCream();
    j["extrasString"] = this->stringifyExtras();

    return j;
}

string Coffee::toString() {
    return this->getSize() + " " + this->getName() + this->stringifyExtras();
}
