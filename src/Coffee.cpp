#include "Coffee.h"

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
    // TODO: Implement price calculation based on extras and size.
    return this->basePrice;
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
