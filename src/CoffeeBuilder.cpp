#include "CoffeeBuilder.h"

CoffeeBuilder::CoffeeBuilder() {
    this->result = new Coffee();
}

void CoffeeBuilder::setName(string name) {
    this->result->setName(name);
}

void CoffeeBuilder::setBeans(Beans beans) {
    this->result->setBeans(beans);
}

void CoffeeBuilder::setSize(Size size) {
    this->result->setSize(size);
}

void CoffeeBuilder::setBasePrice(double basePrice) {
    this->result->setBasePrice(basePrice);
}

void CoffeeBuilder::withSugar() {
    this->result->addSugar();
}

void CoffeeBuilder::withCocoa() {
    this->result->addCocoa();
}

void CoffeeBuilder::withCinnamon() {
    this->result->addCinnamon();
}

void CoffeeBuilder::withMilk() {
    this->result->addMilk();
}

void CoffeeBuilder::withCream() {
    this->result->addCream();
}

Coffee CoffeeBuilder::getResult() {
    return *this->result;
}

void CoffeeBuilder::reset() {
    delete this->result;
    this->result = new Coffee();
}
